void  Print(BinaryTreeNode* pRoot)
{
	if(pRoot==nullptr)
		return;

	std::deque<BinaryTreeNode*> nodes;

	int needPrint = 1;
	int curLevelPrint = 0;

	while(nodes.size()!=0)
	{
		BinaryTreeNode* pNode = nodes.front();
		nodes.pop_front();

		printf("%d ",nodes->m_nValue);
		needPrint--;

		if(pNode->m_pLeft!=nullptr)
		{
			curLevelPrint++;
			nodes.push_back(pNode->m_pLeft);
		}
		if(pNode->m_Right!=nullptr)
		{
			curLevelPrint++;
			nodes.push_back(pNode->m_pLeft);
		}
		if(needPrint==0)
		{
			needPrint = curLevelPrint;
			curLevelPrint = 0;
			printf("\n");
		}
	}
}
