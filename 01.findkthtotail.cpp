//找出一个链表的倒数第k个节点

#include<iostream>

ListNode* FindKthToFail(ListNode* pListHead,unsigned int k)
{
	if(oListHead == NULL)
		return NULL;
	
	ListNode *pAhead = pListHead;
	ListNode *pBehind = pListHead;

	for (unsigned int i=0;i<k-1;i++)
	{
		pAhead = pAhead->m_next;
		if (pAhead == NULL)
		{
			//元素不够
			return NULL;
		}
	}

	while (pAhead-<m_next != NULL)
	{
		pAhead = pAhead.m_next;
		pBehind = pBehind.m_next;
	}
	return pBehind;
}
