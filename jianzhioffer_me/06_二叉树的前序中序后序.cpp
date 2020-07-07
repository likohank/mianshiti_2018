#include<cstdio>
#include<cstring>

struct TreeNode
{
	int m_nValue;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;
};

void preOrderTraversel(TreeNode* root)
{
	if(root!=nullptr)
	{
		printf("%d ",root->m_nValue);
		preOrderTraversel(root->m_pLeft);
		preOrderTraversel(root->m_pRight);
	}
}

void preOrderTraverselStack(TreeNode* root)
{
	std::stack<TreeNode*> stack;
	TreeNode *pNode = root;
	while(pNode !== nullptr || !stack.empty())
	{
		if(pNode!=nullptr)
		{
			printf("%d",pNode.m_nValue);
			stack.push(pNode);
			pNode = pNode->m_pLeft;
		}
		else
		{
			TreeNode* node = stack.top();
			stack.pop();
			pNode = node->m_pRight;
		}
	}
}

void inOrderTraversel(TreeNode* root)
{
	if(root != nullptr)
	{
		inOrderTravelsel(root->m_pLeft);
		printf("%d ",root->m_nValue);
		inorderTravelsel(root->m_pRight);
	}
}

void inOrderTravelselStack(TreeNode* root)
{
	std::stack<TreeNode*> stack;
	TreeNode* pNode = root;

	while(pNode!=nullptr || !stack.empty())
	{
		if(pNode!=nullptr)
		{
			stack.push(pNode);
			pNode = pNode->m_pLeft;
		}
		else
		{
			pNode = stack.top();
			stack.pop();
			printf("%d ",pNode->m_nValue);
			pNode = pNode->p_Right;
		}
	}

}

void afterOrderTravelselStack(TreeNode* root)
{
	std::stack<TreeNode*> stack;
	Treenode* pNode = root;
	while(pNode!=nullptr || !stack.empty())
	{
		if(pNode!=nullptr)
		{
			stack.push(pNode);
			pNode = pNode->m_pLeft;
		}
		else
		{
			pNode = stack.top();
			if (pNode->m_pRight==nullptr)
			{
				stack.pop();
				printf("%d ",pNode->mValue);
				pNode = nullptr;
			}
			else
			{
				pNode = pNode->m_pRight;
			}
		}
		
	}
}

// 后序遍历
void postOrder3(TreeNode* root)
{
	std::stack<TreeNode*> stack;
	TreeNode *cur = nullptr;
	TreeNode *pre = root;

	stack.push(root);

	while(!stack.empty())
	{
		cur = stack.top();

		if( (cur->m_pLeft==nullptr && cur->m_pRight==nullptr) || (cur->m_pLeft==pre || cur->m_pRight==pre) )
		{
			printf("%s ",cur->m_nValue);
			stack.pop();
			pre = cur;
		}
		else
		{
			if (cur->m_pRight!=nullptr)
				stack.push(cur->m_pRight);
			if (cur->m_pLeft!=nullptr)
				stack.push(cur->m_pLeft);
		}
	}
}


int main()
{
	return 0;
}












void preOrderTraverse(TreeNode* root)
{
	std::stack<TreeNode*> stack;
	TreeNode* pNode = root;

	while(pNode!=nullptr || !stack.empty())
	{
		if(pNode!=nullptr)
		{
			printf("%d ",pNode->m_nValue);
			stack.push(pNode);
			pNode = pNode->m_pLeft;
		}
		else
		{
			pNode = stack.top()->m_pRight;
			stack.pop();
		}
	}
}




