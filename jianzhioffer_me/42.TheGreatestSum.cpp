bool g_InvalidInput = false;

int FindGreatestSumOfSubArry(int *pData,int length)
{
	if(pData==nullptr || length<=0)
	{
		g_InvalidInput=true;
		return 0;
	}

	g_InvalidInput = false;

	int nCurSum = 0;
	int nGreatestSum = 0;
	for(int i=0;i<length;i++)
	{
		if(nCurSum<0)
			nCurSum = pData[i];
		else
		{
			nCurSum += pData[i];
		}

		if(nCurSum>nGreatestSum)
			nGreatestSum = nCurSum;
	}
	return nGreatestSum;
}
