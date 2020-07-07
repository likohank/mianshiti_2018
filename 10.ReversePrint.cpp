#include<cstdio>
#include<cstring>

struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
}

void PrintRerversing_Iteratively(ListNode* pHead)
{
	std::stack<ListNode*> nodes;
	ListNode* pNode = pHead;
	while(pNode!=nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while(!nodes.empty())
	{
		pNode = nodes.top();
		printf("%d\n",pNode->m_nValue);
		nodes.pop();
	}
}

void PrintListReversing_Recursively(ListNode* pHead)
{
	if(pHead!=nullptr)
	{
		if (pHead->m_pNext != nullptr)
		{
			PrintListReversing_Recursively(pHead->m_pNext);
		}
		printf("%d\n",pHead->m_nValue);
	}
}

int main()
{
	return 0;
}
