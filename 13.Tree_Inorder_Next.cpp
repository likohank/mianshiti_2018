#include<cstdio>
#include<cstring>

struct TreeNode
{
	int m_nValue;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;
	TreeNode* m_pFather;
};

TreeNode* FindInorderNext(TreeNode* pNode)
{
	if(pNode == nullptr)
		return nullptr;

	TreeNode* pCur = pNode->m_pRight;
	if(pCur!=nullptr)
	{
		while(pCur->m_pLeft!=nullptr)
			pCur = pCur->m_pLeft;
		return pCur;
	}
	else
	{
		pCur = pNode;
		while(pCur->m_pFather!=nullptr)
		{
			if(pCur==pCur->m_pFather->m_pLeft)
				return pCur->m_pFather;
			else
			{
				pCur = pCur->m_pFather;
			}
		}
		return nullptr;
	}

}

int main()
{

}
