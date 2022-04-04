#include <conio.h>
#include <iostream>
#include <complex>
#include <vector>
#include <fstream>
#include <cgraph.h>
#include <gvc.h>
#include <string>
#include <stack>

using std::cout;
using std::cin;
using std::endl;

//connect graphviz to this lab

class treeNode
{
public:
    std::complex<int> value;
    treeNode* parent;
    treeNode* left;
    treeNode* right;
    treeNode(treeNode* p, std::complex<int> v) : parent(p), value(v), left(nullptr), right(nullptr)
    {
    }
    treeNode() :parent(nullptr),left(nullptr),right(nullptr)
    {
    }
private:

};

class tree
{
public:
    treeNode* root;
    std::vector<std::complex<int>> nodes;
    std::vector<int> frequencies;
    void readFromFile();
    tree()
    {
        root = nullptr;
        readFromFile();
    }
    tree(treeNode* node)
    {
        root = node;
        readFromFile();
    }

    void sort();
    //returns cost of the minimal binary tree, saves sequence of nodes for building a tree
    int buildMinBinTree();
    
    //draws graph parsing the tree
    void drawg(std::vector<std::vector<std::vector<std::complex<int>>>> roots);
    //builds tree from the sequence of nodes, returns root pointer
    treeNode* buildtree(std::vector<std::vector<std::vector<std::complex<int>>>> roots, std::string& str);
private:
    
    int sum(int i, int j);
};

treeNode* tree::buildtree(std::vector<std::vector<std::vector<std::complex<int>>>> roots, std::string &str)
{
    int size1 = roots.size();
    int size2 = roots[0][size1 - 1].size();
    if (root != nullptr)
        delete root;
    root = new treeNode(nullptr, roots[0][size1-1][0]);
    for (int i = 1; i < size2; i++)
    {
        treeNode* node = root;

        while (node != nullptr)
        {
            
            if (std::norm(node->value) == std::norm(roots[0][size1-1][i]))
                if (node->value.real() < roots[0][size1 - 1][i].real())
                {
                    if (!node->right) {
                        node->right = new treeNode(node, roots[0][size1 - 1][i]);
                        break;
                    }
                    else
                    node = node->right;
                }
                else {
                    if (!node->left) {
                        node->left = new treeNode(node, roots[0][size1 - 1][i]);
                        break;
                    }
                    else
                    node = node->left;
                }
            else if (std::norm(node->value) < std::norm(roots[0][size1 - 1][i]))
                if (!node->right) {
                    node->right = new treeNode(node, roots[0][size1 - 1][i]);
                    break;
                }
                else
                    node = node->right;
            else
                if (!node->left) {
                    node->left = new treeNode(node, roots[0][size1 - 1][i]);
                    break;
                }
                else
                    node = node->left;
        }
      

        

    }

    std::stack<treeNode*> st;
    st.push(root);
    while (!st.empty())
    {
        treeNode* node = st.top();
        st.pop();

        if (node->left) {
            
            st.push(node->left);
            str.append("\n \"" + std::to_string(node->value.real()) + "+ i" + std::to_string(node->value.imag()) + "\"" + " -> "
            + " \"" + std::to_string( node->left->value.real()) + "+ i" + std::to_string(node->left->value.imag()) + "\" ");
        }
        if (node->right) {
            st.push(node->right);
            str.append("\n \"" + std::to_string(node->value.real()) + "+ i" + std::to_string(node->value.imag()) + "\"" + " -> "
                + " \"" + std::to_string(node->right->value.real()) + "+ i" + std::to_string(node->right->value.imag()) + "\" ");
        }
    }

    str.append("\n }");
    return root;
}

void tree::drawg(std::vector<std::vector<std::vector<std::complex<int>>>> roots)
{
    std::string str="digraph { ";

    
    this->buildtree(roots,str);
    Agraph_t* graph;
    Agraph_t* G;
    GVC_t* gvc;
    gvc = gvContext(); 
    G = agmemread(str.c_str());
    gvLayout(gvc, G, "dot"); 
    gvRenderFilename(gvc,G, "png", "out.png");
    gvFreeLayout(gvc, G); 
    agclose(G); 
    gvFreeContext(gvc);

}

void tree::readFromFile()
{
    std::ifstream f1;
    f1.open("numbers.txt" );
    int real, img, freq;
    while (!f1.eof())
    {
        f1 >> real;
        f1 >> img;
        f1 >> freq;
        nodes.push_back(std::complex<int>(real, img));
        frequencies.push_back(freq);
    }
    f1.close();
}

int tree::buildMinBinTree()
{
    const int size = nodes.size();
    
    std::vector<std::vector<int>>cost(size,std::vector<int>(size,0));
    std::vector<std::vector<std::vector<std::complex<int>>>> roots(size, std::vector<std::vector<std::complex<int>>>(size,std::vector<std::complex<int>>(1)));
        
    

    for (int i = 0; i < size; i++) {
        cost[i][i] = frequencies[i];
        roots[i][i][0]=nodes[i];
    }

    for (int L = 2; L <= size; L++)
    {
        // i is row number in cost[][]
        for (int i = 0; i <= size - L ; i++)
        {
            // Get column number j from row number i and

            int j = i + L -1 ;
            int minR;

            // Try making all keys in interval keys[i..j] as root
           
          
                cost[i][j] = INT_MAX;
                for (int r = i; r <= j; r++)
                {
                    // c = cost when keys[r] becomes root of this subtree
                    int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        sum(i, j);
                   
                    if (c < cost[i][j])
                    {
                        minR = r;
                        cost[i][j] = c;

                        roots[i][j].clear();
                        
                        if (r > i)
                            roots[i][j].insert(roots[i][j].begin(), roots[i][r-1].begin(), roots[i][r-1].end());
                        if(r<j)
                            roots[i][j].insert(roots[i][j].begin(), roots[r+1][j].begin(), roots[r+1][j].end());
                        
                    }
                    

                }
            
                roots[i][j].emplace(roots[i][j].begin(),nodes[minR]);

            
        }
    }
    this->drawg(roots);
        return cost[0][size - 1];
}

int tree::sum(int i, int j)
{
    int res = 0;
    for (int k = i; k <= j; k++)
        res += frequencies[k];
    return res;
}
int main()
{
    tree r;
    int size = 10;
    std::vector<std::vector<int>>cost(size, std::vector<int>(size, 0));
    r.buildMinBinTree();



    return 0;
}