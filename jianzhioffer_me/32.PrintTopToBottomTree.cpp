void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot)
{
	if(pTreeRoot==nullptr)
		return;

	std::deque<BinaryTreeNode*> dequeTreeNode;

	dequeTreeNode.push_back(pTreeNode);

	while(dequeTreeNode.size()!=0)
	{
		BinaryTreeNode* pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();

		printf("%d ",pNode->m_nValue);
		if(pNode->m_pLeft!=nullptr)
			dequeTreeNode.push_back(pNOde->m_pLeft);
		if(pNode->m_pRight!=nullptr)
			dequeTreeNode.push_back(pNOde->m_pRight);

	}
}
