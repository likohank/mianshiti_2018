#include<cstdio>
#include<cstring>

void Unit(char* lable,char* content,char* result)
{
	if(lable==NULL || content==NULL || result==NULL)
		return;

	strcat(result,"<");
	strcat(result,lable);
	strcat(result,">");
	strcat(result,content);
	strcat(result,"</");
	strcat(result,lable);
	strcat(result,">");
}

int main()
{
	char pResult[100+1] = {'\0'};
	Unit("src","12345",pResult);
	Unit("pwd","abc",pResult);

	printf("%s\n",pResult);
	return 0;
}
