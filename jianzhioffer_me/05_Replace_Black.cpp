#include<cstdio>
#include<cstring>

void ReplaceBlack(char string[],int length)
{
	if(string==nullptr || length<0)
		return;
	int originalLength = 0;
	int numberOfBlack = 0;
	int i = 0;

	while(string[i]!='\0')
	{
		++originalLength;
		if( string[i] == ' ')
			++numberOfBlack;
		++i;
	}

	int newLength = originalLength + numberOfBlack*2;
	if (newLength>length)
		return;

	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;

	while(indexOfOriginal>0 && indexOfNew>indexOfOriginal)
	{
		if (string[indexOfOriginal]!=' ')
		{
			string[indexOfNew--] = string[indexOfOriginal];
		}
		else
		{
			string[indexOfNew--] = 'C';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		--indexOfOriginal;
	}
}


int main()
{
	char test[50] = {'\n'};
	strcpy(test,"We are Family!");
	ReplaceBlack(test,50);
	printf("%s\n",test);

	return 0;
}
