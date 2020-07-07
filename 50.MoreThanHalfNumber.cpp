int MoreThanHalfNum(int* numbers,int length)
{
	if(numbers==nullptr || length<=0)
		return 0;

	int result = numbers[0];
	int times = 1;

	for(int i =1;i<length;i++)
	{

		if(times==0)
		{
			result = numbers[i];
			times=1;
			continue
		}

		if(result==numbers[i])
		{
			times++;
		}
		else
		{
			times--;
		}
	}
	return result;
}
