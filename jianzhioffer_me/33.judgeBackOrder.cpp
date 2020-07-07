bool judgeBackOrder(int* sequence,int length)
{
	if(sequence==nullptr || length<=0)
		return false;

	int i = 0;
	for(i=0;i<length-1;i++)
	{
		if( *(sequence+i) > *(sequence+length-1) )
			break;
	}

	int j=i;
	for(;j<length-1;j++)
	{
		if( *(sequence+j) < *(sequence+length-1) )
			return false;
	}

	bool left = true;
	if(i>0)
	{
		left = judgeBackOrder(sequence,i);
	}
	bool right = true;
	if(i<length-1)
	{
		right = judgeBackOrder(sequence+i,length-1-i);
	}

	return left&&right;

}
