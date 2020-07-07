int digitAtIndex(int index)
{
	if(index<0)
		return -1;

	int digits = 1;
	while(true)
	{
		int numbers = countOfIntergers(digits);
		if(index<numbers*digits)
			return digitAtIndex(index,digits);
		index -= digits*numbers;
		digits++;
	}
	return -1;
}

int countOfIntergers(int digits)
{
	if(digits==1)
		return 10;

	int count = std::pow(10,digits-1);
	return 9*count;
}

int digitAtIndex(int index,int digits)
{
	int number = beginNumber(digits) + index/digits;
	int indexFromRight = digits - index%digits;
	for (int i = 0;i<indexFromRight;++i)
		number/=10;
	return number%10;
}

int beginNumber(int digits)
{
	if(digits==1)
		return 0;
	return (int)std::pow(10,digits-1);
}
