#include<cstdio>
#include<cstring>

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

void AddToTail(ListNode** pHead,int value)
{
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;

	if(*pHead == nullptr)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;

		while(pNode->m_pNext!=nullptr)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = pNew;
	}
}

void RemoveNode(ListNode** pHead,int value)
{
	if(pHead == nullptr || *pHead== nullptr)
		return;

	ListNode* pToBeDelete = nullptr;

	if((*pHead)->m_nValue == value)
	{
		pToBeDelete = *pHead;
		*pHead = *pHead->pNext;
	}
	else
	{
		ListNode* pNode = *pHead;
		while(pNode->m_pNext!=nullptr && pNode->m_pNext->m_nValue != value)
			pNode = pNode->m_pNext;

		if(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
		{
			pToBeDelete = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->pNext;
		}
	}

	if(pToBeDelete != nullptr)
	{
		delete pToBeDelete;
		pToBeDelete = nullptr;
	}
}

int main()
{
	/*
	char* aa = "12345";
	printf("%d\n",sizeof(aa));
	printf("%d\n",strlen(aa));

	char bb[] = "12345";
	printf("%d\n",sizeof(bb));
	printf("%d\n",strlen(bb));
	*/
	//int& aa[3];   //wrong
	//
	
	/*
	char str[10];
	strcpy(str,"0123456789");
	printf("%s!\n",str);
	printf("%d\n",strlen(str));
	printf("%d\n",sizeof(str));
	*/

	/*
	char* st1 = "Hello";
	char* st2 = "Hello";

	printf("%x \t %x \n",st1,st2);
	printf("%x \t %x \n",st1,st2);
	*/

	int a1[10] = {1,2,3};
	for(int i=0;i<10;i++)
		printf("%d\n",a1[i]);

	return 0;
}
