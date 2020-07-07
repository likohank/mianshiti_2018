void Reverse(char* pBegin,char* pEnd)
{
	if(pBegin==nullptr || pEnd==nullptr)
		return ;

	while(pBegin<pEnd)
	{
		char temp = *pBegin;
		*pBegin  = *pEnd;
		*pEnd = temp;

		pBegin++;
		pEnd--;
	}
}

void ReverseSentence(char* pData)
{
	if(pData == nullptr)
		return;

	char* pBegin = pData;
	char* pEnd = pData;

	while(pEnd!='0')
		pEnd++;
	pEnd--;

	Reverse(pBegin,pEnd);

	pBegin = pEnd = pData;
	while(pBegin!='\0')
	{
		if(*pBegin==' ')
		{
			pBegin++;
			pEnd++;
		}
		else if(*pEnd==' ' || *pEnd=='\0')
		{
			pEnd--;
			Reverse(pBegin,pEnd);
			pBegin = pEnd+1;
			pEnd = pEnd+1;
		}
		else
			pEnd++;
	}
	return pData;
}
