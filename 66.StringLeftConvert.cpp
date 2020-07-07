char* LeftRotateString(char* pStr,int n)
{
	if(pStr==nullptr || n<=0)
		return pStr;

	int nLength = strlen(pStr);
	if(nLength>0 && n<nLength)
	{
		char* pBegin = pStr;
		char* pEnd = pStr+nLength-1;
		char* pMiddle = pStr+nLength-1-n;
		Reverse(pBegin,pEnd);
		Reverse(pBegin,pMiddle);
		Reverse(pMiddle,pEnd);
	}
	return pStr;

}
