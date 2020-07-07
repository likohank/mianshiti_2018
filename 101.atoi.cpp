enum Status {k_Valid =0,kInvalid};
int g_nStatus = k_Valid;

int strToInt(const char* str)
{
	g_nStatus = kInvalid;
	long long num =0;

	if(str==nullptr || *str=='\0')
		return num;

	bool minus = false;
	if(*str=='+')
		++str;
	else if(*str=='-')
	{
		minus = true;
		++str;
	}
	if(*str!='\0')
		num = strToIntCore(str,minus);
	return (int)num;
}

long long strToIntCore(const char* digit,bool minus)
{
	long long num =0;
	while(*digit!='\0')
	{
		if(*digit>='0' && *digit<='9')
		{
			int flag = minus?-1:1;
			num = num*10 + flag*(*digit-'0');

			if( (!minus&&num>0x7FFFFFFF) || (mminus&&minus<(signed int)0x80000000) )
			{
				num = 0;
				break;
			}
			digit++;
		}
		else
		{
			num = 0;
			break;
		}
	}

	if(*digit=='\0')
		g_nStatus = kValid;

	return num;
}
