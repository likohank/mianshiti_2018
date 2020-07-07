void Print(BinaryTreeNode* pRoot)
{
	if(pRoot==nullptr)
		return;

	std::stack<BinaryTreeNode*> stackNodes[2];
	stackNodes[0].push(pRoot);

	while(!stackNodes[0].empty() || !stackNodes[1].empty())
	{
		if(!stackNodes[0].empty())
		{
			while(!stackNodes[0].empty())
			{
				BinaryTreeNode* pNode = stackNodes[0].top();
				stackNodes[0].pop();
				printf("%d ",pNode->m_nValue);

				stackNodes[1].push(pNode->m_pLeft);
				stackNodes[1].push(pNode->m_pRight);
			}
			printf("\n");
		}
		if(!stackNodes[1].empty())
		{
			while(!stackNodes[1].empty())
			{
				BinaryTreeNode* pNode = stackNodes[1].top();
				stackNodes[1].pop();
				printf("%d ",pNode->m_nValue);

				stackNodes[0].push(pNode->m_pRight);
				stackNodes[0].push(pNode->m_pLeft);
			}
			printf("\n");
		}
	}
}
