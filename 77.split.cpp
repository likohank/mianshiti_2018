#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char** split(char* string,const char delimiter)
{
	int length=0, count=0, i=0, j=0;
	char* str_tmp = string;
	while(*str_tmp)
	{
		if(*str_tmp++==delimiter)
			count++;
		length++;
	}
	char** arry = (char**)malloc(sizeof(char*)*(count+2));
	char** base = arry;

	for(i=0;i<count+1;i++)
	{
		j=0;
		while(string[j]!=delimiter && string[j]!='\0') j++;
		j++;
		printf("%d !!!\n",j);
		*arry = (char*)malloc(sizeof(char)*j);
		memcpy(*arry,string,j-1);
		(*arry)[j-1] = '\0';
		arry++;
		string += j;
	}
	*arry = NULL;
	return base;
}

int main(void)
{
	char* string = "123 456  789 0!";
	char** res = split(string,' ');
	while(*res)
		printf("%s++\n",*res++);
	return 0;

}
