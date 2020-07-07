void Permutation(char* str)
{
	if(str==nullptr)
		return;
	Permutation(str,str);
}

void Permutation(char* pStr,char* pStart)
{
	if(pStart=='\0')
	{
		printf("%s\n".pStr);
		return;
	}
	else
	{
		for(char* pCh=pStart;pCh!='\0',pCh++)
		{
			char tmp = *pCh;
			*pCh = *pStart;
			*pStart = tmp;

			Premutation(pStr,pStart+1);

			tmp = *pCh;
			*pCh = *pStart;
			*pStart = tmp;
		}
	}
}
