void ReorderOddEven(int* pData,unsigned int length)
{
	if(pData==nullptr || length==0)
		return;

	int* pBegin = pData;
	int* pEnd   = pData+length-1;

	while(pBegin<pEnd)
	{
		while(pBegin<pEnd && !isEven(*pBegin))
			++pBegin;
		while( pBegin<pEnd && isEven(*pEnd) )
			--pEnd;
		if(pBegin<pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

bool isEven(int n)
{
	return (n&1)==0;
}
