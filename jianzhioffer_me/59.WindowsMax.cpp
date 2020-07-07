vector<int> maxInWindows(const vector<int>& num,unsigned int size)
{
	vector<int> maxList;
	deque<int> index;
	if(num==nullptr || size==0)
		return maxList;

	for(int i=0;i<size;i++)
	{
		while(!index.empty() && num[i]>num[index.back()])
			index.pop_back();
		index.push_back(i);
	}

	for(int i=size;i<num.size();i++)
	{
		maxList.push_back(num[index.front()]);

		while(!index.empty() && num[i]>num[index.back()])
			index.pop_back();

		if(!index.empty() && (i-index.front())>=size)
			index.pop_front();

		index.push_back(i);
	}
	maxList.push_back(num[index.front()]);
	return maxList;
}
