#include<cstdio>
#include<stdexcept>

int Min(int* numbers,int length)
{
	if(numbers==nullptr || length<=0)
	{
		std::logic_error ex("error");
		throw std::exception(ex);
	}

	int index1=0;
	int index2 = length -1 ;
	int indexMid = index1;

	while(numbers[index1]>=numbers[index2])
	{
		if(index2-index1 == 1)
		{
			indexMid = index2;
			break;
		}

		indexMid = (index1+index2)/2;

		if(numbers[index1]==numbers[index2] && numbers[index1]==numbers[indexMid])
		{
			++index1;
			continue;
		}

		if(numbers[indexMid]>=numbers[index1])
			index1 = indexMid;
		else if (numbers[indexMid]<=numbers[index2])
			index2 = indexMid;
	}
	printf("%d\n",indexMid);
	return numbers[indexMid];
}

int main()
{
	int a[] = {5,5,5,5,5,5,5,5,5,6,7,1,5};
	int res = Min(a,sizeof(a)/sizeof(int));
	printf("%d\n",res);

	int b[] = {5,5,5,5,5,5,5,5};
	res = Min(a,sizeof(b)/sizeof(int));
	printf("%d\n",res);

	return 0;
}
