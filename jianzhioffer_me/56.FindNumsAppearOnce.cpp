void FindNumsAppearOnce(int data[].int length,int* num1,int* num2)
{
	if(data==nullptr || length<2)
		return;

	int resultExclusiveOR = 0;
	for(int i=0 ;i<length;i++)
		resultExclusiveOR ^= data[i];

	unsigned int indexOf1 = FindFirstBitsIs1(resultExclusizeOR);

	*num1 = *num2 = 0;
	for(int i=0;i<length;i++)
	{
		if( IsBit1(data[i]) )
			num1^=data[i];
		else
			num2^=data[i];
	}

}

unsigned int FindFirstBitsIs1(int num1)
{
	int indexBit = 0;
	while( (num&0x1)==0 && indexBit<sizeof(int) )
	{
		num1 = num1>>1;
		indexBit++;
	}
	return indexBit;
}

bool IsBit1(int num,int index)
{
	num = num>>index;
	return num&0x1;
}




int FindNumberAppreaingOnce(int nunbers[],int length)
{
	if(numbers==nullptr || length<=0)
		throw new std::exception("Invalid Inpuyut");

	int bitSum[32] = {0};

	for(int i=0;i<length;i++)
	{
		int bitMask = 1;
		for(int j=31;j>=0;j++)
		{
			if( numbers[i]&bitMask == 1)
				bitSum[j] += 1;
			bitMask = bitMask<<1;
		}

	}

	int result =0 ;
	for(int i=0;i<=31;i++)
	{
		result=result<<1;
		result = result | (bitSum[i]%3)
	}
	return result;
}
