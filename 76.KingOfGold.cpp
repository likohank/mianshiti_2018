//国王挖金矿问题

#include<iostream>
using namespace std;

int getMostGold(int n,int w,int* g ,int* p)
{
	int* preResults = new int[w+1];
	int* results = new int[w+1];

	//填充边界格子的值
	for(int i=0;i<=w;i++)
	{
		if(i<p[0])
			preResults[i]=0;
		else
			preResults[i] = g[0];
	}

	//for(int j=0;j<=w;j++)
	//	cout <<preResults[j] << " ";
	//cout<<endl;

	//填充其余格子的值，
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=w;j++)
		{
			if(j<p[i])
				results[j] = preResults[j];
			else
				results[j] = (preResults[j]>(preResults[j-p[i]]+g[i])) ? (preResults[j]) : (preResults[j-p[i]]+g[i]);
		}
		//for(int j=0;j<=w;j++)
		//	cout <<results[j] << " ";
		//cout<<endl;

		int* tmp = results;
		results = preResults;
		preResults = tmp;
	}

	int max = preResults[w];
	delete preResults;
	delete results;

	return max;
}

int main(void)
{
	int n = 5;
	int w = 10;
	int g[5] = {400,500,200,300,350};
	int p[5] = {5,5,3,4,3};
	int max = getMostGold(n,w,g,p);
	cout<<"max: "<<max<<endl;
	return 0;
}
