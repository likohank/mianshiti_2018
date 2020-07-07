#include<cstdio>
#include<cstring>

void DeleteDuplication(ListNode** pHead)
{
	if(pHead == nullptr || *pHead==nullptr)
		return;

	ListNode* pNode = *pHead;
	ListNode* pPreNode = nullptr;

	while(pNode!=nullptr)
	{
		ListNode* pNext = pNode->m_pNext;
		bool isNeedDel = false;

		if(pNext!=nullptr && pNode->m_nValue==pNext->m_nValue)
			isNeedDel = true;

		if(!isNeedDel)
		{
			pPreNode = pNode;
			pNode = pNext;
		}
		else
		{
			int nDel = pNode->m_nValue;
			while(pNode!=nullptr)
			{
				if(pNode->m_nValue == nDel)
				{
					pNext = pNode->m_pNext;
					delete pNode;
					pNode = pNext;
				}
				else
				{
					break;
				}
			}

			if(pPreNode==nullptr)
				*pHead = pNext;
			else
			{
				pPreNode->m_pNext = pNext;
			}
		}
	}
}

int main()
{
	return 0;
}
