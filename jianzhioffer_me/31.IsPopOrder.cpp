bool IsPopOrder(int* pPush,int* pPop,int length)
{
	bool pPossible = false;
	if(pPush==nullptr || pPop==nullptr || length<=0)
		return false;

	std::stack<int> stackData;
	int* pPrePush = pPush;
	int* pPrePop = pPop;

	while(pPrePush-pPush<length)
	{
		int num = *(pPrePush);
		stackData.push(num);

		while(stackData.empty()==false && *pPrePop==stackData.top())
		{
			stackData.pop();
			pPrePop++;
		}
		pPrePush++;
	}

	return stackData.empty();
}
