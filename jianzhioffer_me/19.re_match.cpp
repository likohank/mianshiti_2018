#include<cstdio>

bool match(char* str, char* pattern)
{
	if(str==nullptr || pattern==nullptr)
		return false;
	return matchCore(str,pattern);
}

bool matchCore(char* str,char* pattern)
{
	if(*str=='\0' && *pattern=='\0')
		return true;

	if(*str!='\0' && *pattern=='\0')
		return false;

	if(*(pattern+1)=='*')
	{
		if(*pattern==*str || (*pattern=='.' && *str!='\0'))
			return matchCore(str+1,pattern+2) || matchCore(str+1,pattern) || matchCore(str,pattern+2);
		// ba*ab 匹配式  对应的 字符串 bab   , 需要进行 matchCore(str,pattern+2) , 因为 a*(匹配式)  的a 虽然能匹配中 字符串的 a，
		// 但是 实际对应 字符串a的是匹配式中的第二个a，所以需要字符串位置不变，进行尝试

		else
		{
			return matchCore(str,pattern+2);
		}
	}
	if(*str==*pattern || (*pattern=='.' && *str!='\0') )
		return matchCore(str+1,pattern+1);

	return false;

}

int main()
{
	return 0;
}
