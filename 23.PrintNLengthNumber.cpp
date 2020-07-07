#include<cstdio>
#include<memory.h>

bool Increment(char* number);
void PrintNumber(char* number);
void PrintCore(char* number,int nLength,int n);


void PrintTomaxOfNDigits(int n)
{
	if(n<0)
		return;

	char* number = new char[n+1];
	memset(number,'0',n);
	number[n] = '\0';

	while(!Increment(number))
	{
		PrintNumber(number);
	}

	delete number;
}

bool Increment(char* number)
{
	bool isOver = false;
	int nTakeOver = 0;
	int nLength = strlen(number);

	for(int i=nLength-1;i>=0;i--)
	{
		int nSum = number[i] - '0';
		if(i==nLength-1)
			nSum ++;
		nSum += nTakeOver;

		if(nSum>=10)
		{
			if(i==0)
				isOver = true;
			nSum -= 10;
			nTakeOver = 1;
			number[i] = '0' + nSum;
		}
		else
		{
			number[i] = '0' + nSum;
			nTakeOver = 0;
			break;
		}
	}
	return isOver;
}


void PrintNumber(char* number)
{
	int nLength = strlen(number);

	int i =0;
	for(i=0;i<nLength;i++)
	{
		if(number[i]!='0')
			break;
	}
	printf("%s\n",number+i);
}

//递归的方式

void PrintToMaxOfNDigits_2(int n)
{
	if(n<0)
		return;

	char* number = new char[n+1];
	memset(number,'0',n);
	number[n] = '\0';

	PrintCore(number,n,0);
	delete[] number;
}

void PrintCore(char* number,int nLength,int n)
{
	if(n==nLength)
	{
		PrintNumber(number);
		return ;
	}
	for(int i=0;i<=9;i++)
	{
		number[n] = '0' + i;
		PrintCore(number,nLength,n+1);
	}
}


int main()
{	
	PrintToMaxOfNDigits_2(3);
	//PrintTomaxOfNDigits(4);
	return 0;
}
