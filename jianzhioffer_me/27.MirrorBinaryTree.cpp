struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void MirrorBinaryTree(BinaryTreeNode* pRoot)
{
	if(pRoot==nullptr)
		return;

	if(pRoot->m_pLeft==nullptr && pRoot->m_Right==nullptr)
		return;

	BinaryTreeNode* pTmp = pRoot->m_pLeft;
	pRoot->m_pLeft = pRoot->m_pRight;
	pRoot->m_pRight = pTmp;

	MirrorBinaryTree(pRoot->m_pLeft);
	MirrorBinaryTree(pRoot->m_pRight;
}
