ListNode* GetFirstSame(ListNode* pHead1,ListNode* pHead2)
{
	if(pHead1 == nullptr || pHead2==nullptr)
		return nullptr;
	int nLength1 = GetLength(pHead1);
	int nLength2 = GetLength(pHead2);
	ListNode* pLong = nLength1>nLeng2?pHead1:pHead2;
	ListNode* pShort = nLength1>nLeng2?pHead2:pHead2;
	int nDiff = nLength1>nLeng2?(nLength1-nLength2):(nLength2-nLength1);

	for(int i=0;i<nDiff;i++)
		pLong=pLong->m_pNext;

	while(pLong!=nullptr)
	{
		if(pLong==pShort)
			break;
		pLong==pLong->m_pNext;;
		pShort=pShort->m_pNext;
	}
	return pLong;
}

int GetLength(ListNode* pHead)
{
	if(pHead==nullptr)
		return 0;

	int nLength;
	ListNode* pNode = pHead;
	while(pNode != nullptr)	
	{
		pNode=pNode->m_pNext;
		nLength++;
	}
	return nLength;
}
