#include<cstdio>
#include<cstring>

bool dumplicate(int numbers[],int length,int* dumplication)
{
	if (numbers ==  nullptr || length == 0 )
		return false;

	for (int i=0;i<length;i++)
	{
		if (numbers[i]<0 || numbers[i]>length-1)
			return false;
	}

	for (int i = 0;i<length,i++)
	{
		while(numbers[i]!=i)
		{
			if(numbers[numbers[i]] == numbers[i])
			{
				*dumplication = numbers[i];
				return true;
			}
			int temp = numbers[numbers[i]];
			numbers[numbers[i]] = temp;
			numbers[i] = temp;
		}
	}
}

int main()
{
	return 0;

}
