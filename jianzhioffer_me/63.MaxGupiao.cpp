#include<cstdio>

int MaxDiff(int* price,int length)
{
	if(price==nullptr || length<2)
		return 0;

	int min = price[0];
	int diff = price[1]-price[0];

	for(int i=1;i<length;i++)
	{
		if((price[i]-min)>diff)
			diff = price[i] - min;

		if(price[i]<min)
			min = price[i];

		printf("%d %d = %d\n",price[i],min,diff);
	}
	return diff;
}

int main()
{
	int num[] = {9,11,8,5,7,12,16,14};
	printf("%d\n",MaxDiff(num,8));
	return 0;
}
