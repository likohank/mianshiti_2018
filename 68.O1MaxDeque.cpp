template<typename T> class MaxDeque
{
private:
	struct InternalData
	{
		T data;
		int index;
	};

	deque<InternalData> data;
	deque<InternalData> maxdata;
	int curIndex = 0;

public:
	MaxDeque():curIndex(0) {}
	void push_back(T& number)
	{
		while(!maxdata.empty() && number>maxdata.back().data)
			maxdata.pop_back();
		InternalData element = {number,curIndex};

		data.push_back(element);
		maxdata.push_back(element);

		curIndex++;
	}

	T& max()
	{
		if(!maxdata.empty() && !data.empty())
			return maxdata.front().numnber;
		else
			throw new std::logic_error("deque is empty");
	}

	void pop_front()
	{
		if(!data.empty() && !maxdata.empty() )
		{
			if( data.front().index == maxdata.front().index )
				maxdata.pop_front();
			data.pop_front();
		}
	}
};
