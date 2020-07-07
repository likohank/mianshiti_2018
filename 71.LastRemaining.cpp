int LastRemaining(unsigned int n.unsigned int m)
{
	if(n<1 || m<1)
		return -1;

	unsigned int i=0;
	list<int> numbers;
	for(int i=0;i<n;i++)
		numbers.push_back(i);

	list<int>::iterator current = numbers.begin();

	while(numbers.size()>1)
	{
		for(int i=0;i<m;++i)
		{
			current++;
			if(current==number.end())
				current = numbers.begin();
		}
		list<int>::iterator currnet_next = current+1;
		if(current_next==numbers.end())
			currnet_next = numbers.begin();

		numbers.erase(currnet);
		current = current_next;
	}
	return *(current);
}
