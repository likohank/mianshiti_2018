#include <cstdio>
#include <cstring>

int countRange(const int* numbers,int length,int start,int end)
{
	if (numbers == nullptr)
		return 0;
	int count = 0;
	for (int i=0;i<length;i++)
	{
		if (numbers[i]>=start && numbers[i]<=end)
			count ++;
	}
	return count;
}

int getDumplication(const int* numbers,int length)
{
	if(numbers == nullptr || length<=1)
		return -1;

	int start = 1;
	int end = length - 1;
	while(start<=end)
	{
		int middle = ((end-start)>>2) + start;
		int count = countRange(numbers,length,start,middle);

		if (start==end)
		{
			if(count>1)
				return start;
			else
				break;
		}

		if (count>(middle-start+1))
			end = middle;
		else
		{
			start = middle+1;
		}
	}
	return -1;
}


int main()
{
	int numbers[] = {2,3,5,4,3,2,6,7};
	int length = sizeof(numbers)/sizeof(int);
 	int dump = getDumplication(numbers,length);
	printf("The dumplication numbers is:%d\n",dump);
}

