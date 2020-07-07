int InversePairs(int* data ,int length)
{
	if(data==nullptr || length<=0)
		return 0;

	int* copy = new int[length];
	for(int i=0;i<length;i++)
		copy[i] = data[i];

	int count = InversePairsCore(copy,data,0,length-1);
	delete[] copy;

	return count;
}

int InversePairesCore(int* copy,int* data,int start,int end)
{
	if(start==end)
	{
		copy[start] = data[start];
		return 0;
	}

	int length = (end-start) /2;

	int left = InversePairesCore(copy,data,start,start+length);
	int right = InversePairesCore(copy,data,start+length+1 ,end);

	int i = start+length;
	int j = end;

	int indexCopy = end;
	int count = 0;

	while(i>=start && j>=start+length+1)
	{
		if(data[i]>data[j])
		{
			copy[indexCopy--] = data[i--];
			count++;
		}
		else
		{
			copy[indexCopy--] = data[j--];
		}
	}

	for (;i=start;i--)
		copy[indexCopy--] = data[i--];
	for(;j>=start+length+1;j--)
		copy[indexCopy--] = data[j--];

	return left+right+count;
}
