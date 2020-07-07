#include<cstdio>
#include<cstring>

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

void DeleteNode(ListNode** pListHead,ListNode* pDelete)
{
	if(pListHead==nullptr || pDelete==nullptr)
		return;

	if(pDelete->m_pNext!=nullptr)
	{
		ListNode* pNext = pDelete->m_pNext;
		pDelete->m_nValue = pNext->m_nValue;
		pDelete->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext = nullptr;
	}
	else if(*pListHead == pDelete)
	{
		delete pDelete;
		pDelete = nullptr;
		*ListHead = nullptr;
	}
	else
	{
		pAhead = *pListHead;
		while(pAhead->m_pNext!=pDelete)
		{
			pAhead = pAhead->m_pNext;
		}
		pAhead->m_pNext = nullptr;
		delete pDelete;
		pDelete = nullptr;
	}
}

int main()
{
	return 0;
}
