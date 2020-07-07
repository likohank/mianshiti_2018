bool FindTwoNumberWithSum(int data[],int length,int* num1, int*num2,int sum)
{
	if(data==nullptr || length<0)
		return false;

	bool found = false;
	int* ahead = data+length-1;
	int* behind = data;

	while(behind<ahead)
	{
		int curSum = *ahead + *behind;
		if( curSum==sum )
		{
			*num1 = *ahead;
			*num2 = *behind;
			found = true;
			break;
		}
		else if(curSum>sum)
		{
			ahead--;
		}
		else
		{
			behind++;
		}
	}
	return found;
}



