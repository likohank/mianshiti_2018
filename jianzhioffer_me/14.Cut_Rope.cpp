#include<cstdio>
#include<cstring>
#include<cmath>

int MaxProductAfterCutting(int length)
{
	if(length<2)
		return 0;
	if(length==2)
		return 1;
	if(length==3)
		return 2;

	int* product = new int[length+1];
	product[0]  = 0;
	product[1] = 1;
	product[2] = 2;
	product[3] = 3;

	int max = 0;
	for(int i=4;i<=length;i++)
	{
		max = 0;
		for(int j=1;j<=i/2;j++)
		{
			int res = product[j]*product[length-j];
			max = (res>max?res:max);
		}
		product[i] = max;
	}
	delete product;
	return max;
}

int maxProductAfterCutting_s2(int length)
{
	if(length<2)
		return 0;
	if(length==2)
		return 1;
	if(length==3)
		return 2;

	int timeCut3 = length/3;
	if(length - timeCut3*3 == 1)
		timeCut3-=1;

	int timeCut2 = (length-timeCut3*3)/2;

	return (int)(pow(3,timeCut3))*(int)(pow(2,timeCut2));
}

int main()
{
	int max = MaxProductAfterCutting(4);
	max = maxProductAfterCutting_s2(8);
	printf("%d\n",max);
}
