struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

ListNode* ReverList(ListNode* pHead)
{
	if(pHead==nullptr || pHead->m_pNext==nullptr)
		return pHead;

	ListNode* pReversedHead = nullptr;
	ListNode* pNode = pHead;
	ListNode* pPre = nullptr;

	while(pNode!=nullptr)
	{
		ListNode* pNext = pNode->m_pNext;

		pReversedHead = pNode;
		pReversedHead->m_pNext = pPre;
		pPre = pReversedHead;

		pNode = pNext;
	}
	return pReversedHead;
}
