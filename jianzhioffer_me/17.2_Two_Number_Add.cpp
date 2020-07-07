#include<cstdio>
#include<memory.h>
#include<stdexcept>

void Add(char* num1,char* num2)
{
	if(num1==nullptr || num2==nullptr)
		return;

	int nLength1 = strlen(num1);
	int nLength2 = strlen(num2);

	if(nLength1<=0 || nLength2<=0)
		return;

	char* numLong = num1;
	char* numShort = num2;
	int nLengthLong = nLength1;
	int nLengthShort = nLength2;
	if(nLength1<nLength2)
	{
		numLong = num2;
		numShort = num1;
		nLengthLong = nLength2;
		nLengthShort = nLength1;
	}

	int newLength = nLengthLong + 1;
	char* result = new char[newLength+1];
	memset(result,'0',newLength);
	result[newLength] = '\0';

	int nTakeOver = 0;
	int i=0 ,j=0 ,k= 0;

	for(i=nLengthLong-1,j=nLengthShort-1,k=newLength-1;j>=0;i--,j--,k--)
	{
		int n1 = numShort[j] - '0';
		int n2 = numLong[i] - '0';
		if( n1>=10 || n1<0 || n2>=10 || n2<0)
		{
			std::logic_error ex("Invalid Char");
			throw std::invalid_argument("Invalid Char");
		}

		int n = n1 + n2 + nTakeOver;
		if( n>=10)
		{
			n -= 10;
			nTakeOver = 1;
		}
		else
		{
			nTakeOver = 0;
		}
		result[k] = n+'0';
	}
	while(i>=0)
	{
		int n1 = numLong[i] - '0';
		if( n1>=10 || n1<0 )
		{
			std::logic_error ex("Invalid Char");
			throw std::exception(ex);
		}

		int n = n1 + nTakeOver;
		if(n>=10)
		{
			n -= 10;
			nTakeOver = 1;
		}
		else
		{
			nTakeOver = 0;
		}
		result[k] = n+'0';
		i--;
		k--;
	}
	if(nTakeOver == 1)
	{
		result[k] = '1';
		printf("%s\n",result);
	}
	else
		printf("%s\n",result+1);


	delete[] result;
}

int main()
{
	char* num1 = "999";
	char* num2 = "0-";

	try
	{
		Add(num1,num2);
	}
	catch(std::invalid_argument  ex)
	{
		printf("%s\n",ex.what());
		printf("SomeThingError\n");
	}
	return 0;
}
