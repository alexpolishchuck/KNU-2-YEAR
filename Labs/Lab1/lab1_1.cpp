#include <iostream>
#include <stdio.h>
#include  <conio.h>
#include <vector>

using namespace std;

template <typename T>
class graph
{
public:
	vector<vector<T>> matrix;
	T i;
	void defsize()
	{
		i = matrix.size();
	}


};

class mystack
{
public:
	vector<int> st;
	int size;
	void add(int number)
	{
		st.push_back(number);
		last++;
	}
	void poplast()
	{
		st.pop_back();
		last--;
	}
	void lastelement(int& element)
	{
		element = st[last];
	}
	void defsize()
	{
		size = st.size();
	}
private:
	int last = -1;

};
template <typename T>
int DeleteVertex(graph<T>& gr, int index)
{
	if (index >= gr.i || index < 0)
		return 0;
	if (index != gr.i - 1)
	{
		for (int i = index; i < gr.i - 1; i++)
			gr.matrix[i] = gr.matrix[i + 1];
		for (int i = 0; i < gr.i - 1; i++)

			for (int j = index; j < gr.i - 1; j++)
				gr.matrix[i][j] = gr.matrix[i][j + 1];

	}


	gr.matrix.resize(gr.i - 1);
	gr.defsize();
	return 0;
}
template <typename T>
void DeleteEdge(graph<T>& gr, int a, int b)
{
	gr.matrix[a][b] = 0;
	gr.matrix[b][a] = 0;

}
template <typename T>
int CreateMinimalSpanningTree(graph<T>& gr)
{
	int size = gr.i;
	if (size == 1)
		return -1;

	vector<bool> isvisited;
	vector <int> parents;
	for (int i = 0; i < size; i++)
		isvisited.push_back(false);
	isvisited[0] = true;
	for (int i = 0; i < size; i++)
		parents.push_back(-1);
	mystack s;

	s.add(0);
	s.defsize();
	int element = -1;
	while (s.size)
	{

		s.lastelement(element);
		isvisited[element] = true;
		T min = 0;
		int index = -1;
		for (int i = 0; i < size; i++)
		{

			if ((min == 0 || gr.matrix[element][i] < min) && gr.matrix[element][i] && !isvisited[i])
			{
				T min1 = 0;
				for (int j = 0; j < size; j++) //verifing that there are no cheaper edges
				{
					if ((min1 == 0 || gr.matrix[i][j] < min1) && gr.matrix[i][j] && isvisited[j] && j != element)
						min1 = gr.matrix[i][j];

				}
				if (min1 == 0 || min1 > gr.matrix[element][i])
				{
					min = gr.matrix[element][i];
					index = i;
				}
			}
			else if (gr.matrix[element][i] && parents[i] != element && parents[element] != i && isvisited[i])
				DeleteEdge(gr, element, i);
		}
		if (index != element && index != -1)
		{


			s.add(index);
			parents[index] = element;

		}
		int last = -1;
		s.lastelement(last);
		if (last == element)
		{
			s.poplast();
			s.defsize();
		}
	}








	return 0; 
}
template <typename T>
int CreateSpanningTree(graph<T>& gr)
{

	int size = gr.i;
	if (size == 1)
		return -1;

	vector<bool> isvisited;
	vector <int> parents;
	for (int i = 0; i < size; i++)
		isvisited.push_back(false);
	isvisited[0] = true;
	for (int i = 0; i < size; i++)
		parents.push_back(-1);
	mystack s;

	s.add(0);
	s.defsize();
	int element = -1;
	while (s.size)
	{

		s.lastelement(element);
		isvisited[element] = true;
		
		for (int i = 0; i < size; i++)
		{
			if (gr.matrix[element][i] && !isvisited[i])
			{
				s.add(i);
				parents[i] = element;
				break;
			}
			else if (gr.matrix[element][i] && parents[i] != element && parents[element] != i)
				DeleteEdge(gr, element, i);
		}
		int last = -1;
		s.lastelement(last);
		if (last == element)
		{
			s.poplast();
			s.defsize();
		}
	}








	return 0; 
}
template <typename T>
void SaveMatrix(graph<T>& gr)
{
	FILE* f1;
	fopen_s(&f1, "New matrix.txt", "w");
	for (int i = 0; i < gr.i; i++)
	{
		for (int j = 0; j < gr.i; j++)
		{
			T number = gr.matrix[i][j];
			int c;
			c = number;
			double d;
			d = number - c;
			int counter = 0;
			while (c != 0)
			{
				c /= 10;
				counter++;
			}
			c = number;
			if (!counter)
				counter++;
			while (counter)
			{
				int a = pow(10, counter - 1);
				a = c / a;
				int b = a % 10;
				fputc(b + '0', f1);
				counter--;
			}
			if (d != 0)
				fputc('.', f1);
			while (d != 0)
			{
				d = d * 10;
				c = d;
				c %= 10;
				d -= c;
				fputc(c + '0', f1);
			}
			if (j != gr.i - 1)
				fputc(' ', f1);
		}
		if (i != gr.i - 1)
			fputc('\n', f1);
	}
	fclose(f1);
}

template<typename T>
void AddEdge(int vertex1, int vertex2, graph<T>& gr)
{
	if (vertex1 >= 0 && vertex1 < gr.i && vertex2 >= 0 && vertex2 < gr.i)
	{
		T a;
		cout << "Enter the weight of the incident edge: " << endl;
		cin >> a;
		if (a >= 0)
		{
			gr.matrix[vertex1][vertex2] = a;
			gr.matrix[vertex2][vertex1] = a;
		}

	}
}
template<typename T>
void AddVertex(graph<T>& gr)
{
	vector<T> edges;
	T a;
	int counter = 0;
	for (int i = 0; i < gr.i; i++)
	{
		system("cls");
		cout << "Vertex = " << i << "      Enter the weight of the incident edge: " << endl;
		cin >> a;
		if (a >= 0)
			edges.push_back(a);
		else
			i--;
		if (a == 0)
			counter++;

	}
	if (counter != gr.i - 1)
	{
		edges.push_back(0);
		gr.matrix.push_back(edges);
		gr.defsize();
		for (int i = 0; i < gr.i - 1; i++)
			gr.matrix[i].push_back(gr.matrix[gr.i - 1][i]);

	}
}

template <typename T>
void functions(graph<T>& gr)
{
	FILE* f1;
	fopen_s(&f1, "matrix.txt", "r");
	char c;
	int i = 0;
	int j = 0;
	T number = 0;
	int counter = 0;
	vector <T> row;
	while (!feof(f1))
	{
		c = fgetc(f1);
		counter = 0;
		bool isdot = false;
		while (c > 47 && c < 58 || c == '.')
		{
			if (c == '.')
			{
				isdot = true;
				c = fgetc(f1);
			}
			if (!number && !isdot)
				number += c - '0';
			else if (isdot)
			{
				counter--;
				number = number + (c - '0') * pow(10, counter);
			}
			else
				number = number * 10 + c - '0';
			c = fgetc(f1);
		}
		row.push_back(number);
		j++;
		number = 0;
		if (feof(f1))
		{
			gr.matrix.push_back(row);
			break;
		}
		else if (c == '\n')
		{
			gr.matrix.push_back(row);
			row.clear();
			i++;
			j = 0;
		}
	}
	fclose(f1);
	gr.defsize();

	for (int k = 0; k <= i; k++)
	{
		for (int l = 0; l < j; l++)
			cout << gr.matrix[k][l] << " ";
		cout << endl;
	}
	cout << "-------------------------" << endl;
	cout << "-------------------------" << endl;
	CreateSpanningTree(gr);

	for (int k = 0; k <= i; k++)
	{
		for (int l = 0; l < j; l++)
			cout << gr.matrix[k][l] << " ";
		cout << endl;
	}
	cout << "-------------------------" << endl;
	cout << "-------------------------" << endl;
	CreateMinimalSpanningTree(gr);
	for (int k = 0; k <= i; k++)
	{
		for (int l = 0; l < j; l++)
			cout << gr.matrix[k][l] << " ";
		cout << endl;
	}

	DeleteVertex(gr, 8);
	for (int k = 0; k < gr.i; k++)
	{
		for (int l = 0; l < gr.i; l++)
			cout << gr.matrix[k][l] << " ";
		cout << endl;
	}

	AddVertex(gr);
	for (int k = 0; k < gr.i; k++)
	{
		for (int l = 0; l < gr.i; l++)
			cout << gr.matrix[k][l] << " ";
		cout << endl;
	}
	cout << "-------------------------" << endl;
	cout << "-------------------------" << endl;
	AddEdge(1, 3, gr);
	for (int k = 0; k < gr.i; k++)
	{
		for (int l = 0; l < gr.i; l++)
			cout << gr.matrix[k][l] << " ";
		cout << endl;
	}

	SaveMatrix(gr);
}
int main()
{
	int answer = 0;
	cout << "Choose: 1 - int , 2 - double" << endl;
	cin >> answer;
	if (answer == 1)
	{
		graph<int> gr;
		functions(gr);
	}
	else if (answer == 2) {
		graph<double> gr;
		functions(gr);
	}

	return 0;
}

/*
0 1 0 0 0 1 0 1
1 0 1 0 1 0 0 0
0 1 0 1 1 0 0 0
0 0 1 0 1 0 0 0
0 1 1 1 0 0 0 0
1 0 0 0 0 0 1 0
0 0 0 0 0 1 0 1
1 0 0 0 0 0 1 0
*/

/*
0 1 1 1
1 0 1 1
1 1 0 1
1 1 1 0
*/

/*
0 60 30 10
60 0 70 90
30 70 0 80
10 90 80 0
*/

/*
0 10 0 0 0 20 0 40
10 0 60 0 10 0 0 0
0 60 0 20 0 0 0 0
0 0 20 0 30 0 0 0
0 10 0 30 0 0 0 0
20 0 0 0 0 0 30 0
0 0 0 0 0 30 0 50
40 0 0 0 0 0 50 0
*/

/*
0 10 0 0 0 20 0 40 0
10 0 60 0 10 0 0 0 0
0 60 0 20 0 0 0 0 0
0 0 20 0 30 0 0 0 0
0 10 0 30 0 0 0 0 0
20 0 0 0 0 0 30 0 0
0 0 0 0 0 30 0 50 60
40 0 0 0 0 0 50 0 0
0 0 0 0 0 0 60 0 0
*/

/*

0 0.5 0 0 0 20 0 40 0
0.5 0 0.3 0 10 0 0 0 0
0 0.3 0 0.7 0 0 0 0 0
0 0 0.7 0 30 0 0 0 0
0 10 0 30 0 0 0 0 0
20 0 0 0 0 0 30 0 0
0 0 0 0 0 30 0 50 60
40 0 0 0 0 0 50 0 0
0 0 0 0 0 0 60 0 0


*/