bool IsContinuous(int* numbers int length)
{
	if(number==nullptr || length<=0)
		return false;

	qsort(numbers,length,sizeof(int),compare);

	int numOfZero=0;
	for(int i=0;i<length;i++)
	{
		if(numbers[i]==0)
			numOfZero++;
		else
			break;
	}

	int behind = numOfZero;
	int ahead = behind + 1;
	int numOfGap = 0;

	while(ahead<length)
	{
		if(number[ahead]==number[behind])
			return false;
		numOfGap += number[ahead]-number[behind] -1;
		behind = ahead;
		ahead++;
	}

	return numOfZero>=numOfGap;
}

int compare(int* num1,int* num2)
{
	return (int*)num1
}
