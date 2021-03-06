#include<cstdio>

long long Fibonacci(n)
{
	int result[2] = [0,1];
	if(n<2)
		return result[n];

	long long fibNMinusOne = 1;
	long long fibNMinusTwo = 0;
	long long fibN 		= 0;

	for (int i=0;i<n-1;i++)
	{
		fibN = fibNMinusOne + fibNMinusTwo;
		fibNMinusTwo = fibNMinusOne;
		fibNMinusOne = fibN;
	}
	return fibN;
}

int main()
{
	return 0;
}
