BinaryTreeNode* Convert(BinaryTreeNode* pRoot)
{
	BinaryTreeNode* pLastNodeInList = nullptr;
	ConvertNode(pRoot,&pLastNodeInList);

	return pLastNodeInList;
}

void ConvertNode(BinaryTreeNode* pRoot,BinaryTreeNode** pLastNodeInList)
{
	if(pRoot==nullptr)
		return;

	BinaryTreeNode* pCur = pRoot;

	if(pCur->m_pLeft!=nullptr)
		Convert(pCur->m_pLeft,pLastNodeInList);

	pCur->m_pLeft = *pLastNodeInList;
	if(*pLastNodeInList!=nullptr)
		*pLastNodeInList->m_pRight = pCur;
	*pLastNodeInList = pCur;

	if(pCur->m_pRight!=nullptr)
		Convert(pCur->m_pRight,pLastNodInList);
}
