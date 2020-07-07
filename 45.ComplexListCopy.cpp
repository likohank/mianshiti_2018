struct ComplexListNode
{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pRadom;
};

ComplexListNode* Copy(ComplexListNode* pHead)
{
	CloneNodes(pHead);
	CloneRandom(pHead);
	return Reconnect(ComplexListNode* pHead)

}

void CloneNodes(ComplexListNode* pHead)
{
	if(pHead==nullptr)
		return;

	ComplexListNode* pNode = pHead;
	while(pNode!=nullptr)
	{
		ComplexListNode* pClone = new ComplexListNode();
		pClone->m_nValue = pNode->m_nValue;
		pClone->m_pNext = pNode->m_pNext;
		pClone->m_pRandom = nullptr;
		pNode->m_pNext = pClone;
		pNode = pClone->m_pNext;
	}
}

void CloneRandom(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;

	while(pNode!=nullptr && pNode->m_pNext!=nullptr)
	{
		ComplexListNode* pClone = pNode->m_pNext;
		ComplexListNode* pRandowm = pNode->m_pRandom;
		if(pRandom != nullptr)
			pClone->m_pRandom = pRandom->m_pNext;
		pNode = pClone->m_pNext;
	}
}

ComplexListNode* Reconnect(ComplexListNode* pHead)
{
	if(pHead==nullptr)
		return nullptr;

	ComplexListNode* pNode = pHead;
	ComplexListNode* pClone = pHead->m_pNext;;
	ComplexListNode* pCloneHead = pClone;

	while(pNode!=nullptr && pNode->m_pNext!=nullptr)
	{
		pClone = pNode->m_pNext;

		pNode->m_pNext = pClone->m_pNext;
		pNode = pNode->m_pNext;

		if(pNode!=nullptr)
			pClone->m_pNext = pNode->m_pNext;
	}
	return pCloneHead;
}

