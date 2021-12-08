#include <iostream>
#include <stdio.h>
#include  <conio.h>
#include <vector>

using namespace std;

class MyDices
{
public:
	vector<vector<double>> dices;
	int size = 0;

	void defsize()
	{
		size = dices.size();
	}
};

class Mysum
{
public:
	vector<int> sum;
	vector<double> prob;
	void addsum(int newsum, double probability)
	{
		defsize();
		if (i == 0)
		{
			sum.push_back(newsum);
			prob.push_back(probability);
		}
		else {
			int j = 0;
			for (j = 0; j < i; j++)
			{
				if (sum[j] == newsum)
				{
					prob[j] += probability;
					break;
				}
			}
			if (j == i)
			{
				sum.push_back(newsum);
				prob.push_back(probability);
			}
		}
		defsize();
	}
private:
	int i;
	void defsize()
	{
		i = sum.size();
	}
};
void findsum(MyDices& ds, Mysum& sums, int& sumofedges, double& prob, int counter)
{
	if (counter == ds.size)
		sums.addsum(sumofedges, prob);
	else
		if (counter < ds.size)
			for (int i = 0; i < ds.dices[counter].size(); i++)
			{
				sumofedges += i + 1;
				prob *= ds.dices[counter][i];
				findsum(ds, sums, sumofedges, prob, counter + 1);
				sumofedges -= i + 1;
				prob /= ds.dices[counter][i];
			}

}
int main()
{
	MyDices ds;
	Mysum sums;


	vector<vector<double>> a = { {0.3,0.7},{0.1 , 0.4, 0.15, 0.35 } };
	ds.dices = a;



	int sumofedges = 0;
	double prob = 1;
	int counter = 0;
	ds.defsize();
	findsum(ds, sums, sumofedges, prob, counter);

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