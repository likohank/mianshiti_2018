struct ListNode
{
	int m_nVal;
	ListNode* m_pNext;
};

ListNode* MergeSortList(ListNode* pHead1,ListNode* pHead2)
{
	if(pHead1==nullptr)
		return pHead2;
	if(pHead2==nullptr)
		return pHead1;

	ListNode* pRun1 = pHead1;
	ListNode* pRun2 = pHead2;
	ListNode* pMergeHead = nullptr;
	ListNode* pNode = nullptr;

	while(pRun1!=nullptr && pRun2!=nullptr)
	{
		ListNode* pCur = nullptr;
		
		if(pRun1->m_nVal<pRun2->m_nVal)
		{
			pCur = pRun1;
			pRun1 = pRun1->m_pNext;
		}
		else
		{
			pCur = pRun2;
			pRun2 = pRun2->m_pNext;
		}

		if(pMergeHead ==  nullptr)
		{
			pMergeHead = pCur;
			pNode = pCur;
		}
		else
		{
			pNode->m_pNext = pCur;
			pNode = pCur;
		}
	}
	return pMergeHead;
}

ListNode* Merge(ListNode* pHead1 , ListNode* pHead2)
{
	if(pHead1==nullptr)
		return pHead2;
	if(pHead2==nullptr)
		return pHead1;

	ListNode* pMergeHead = nullptr;

	if(pHead1->m_nVal<pHead2->m_nVal)
	{
		pMergeHead = pHead1;
		pMeegeHead->m_pNext = Merge(pHead1->m_pNext.pHead2);
	}
	else
	{
		pMergeHead = pHead2;
		pMergeHead->m_pNext = Merge(pHead1.pHead2->m_pNext);
	}
	return pMergeHead;
}
