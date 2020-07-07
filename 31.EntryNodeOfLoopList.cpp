ListNode* MeetingNode(ListNode* pHead)
{
	if(pHead==nullptr)
		return nullptr;

	ListNode* pSlow = pHead->m_pNext;
	if(pSlow==nullptr)
		return nullptr;
	ListNode* pFast = pSlow->m_pNext;
	while(pFast!=nullptr && pSlow!=nullptr)
	{
		if(pFast==pSlow)
			return pFast;

		pSlow = pSlow->m_pNext;
		pFast = pFast->m_pNext;
		if(pFast!=nullptr)
			pFast=pFast->m_pNext;
	}
	return nullptr;
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	ListNode* pMeet = MeetingNode(pHead);
	if(pMeet==nullptr)
		return nullptr;

	int nodesOfLoop = 1;
	ListNode* pLoop = pMeet;
	while(pLoop->m_pNext!=pMeet)
	{
		pLoop = pLoop->m_pNext;
		nodesOfLoop++;
	}

	pLoop = pHead;
	ListNode* pBehind = pHead;
	for(int i=0;i<nodesOfLoop;i++)
		pLoop = pLoop->m_pNext;
	while(pLoop!=pBehing)
	{
		pLoop = pLoop->m_pNext;
		pBehind = pBehind->m_pNext;
	}
	return pBehind;
}
