struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

bool isSymmertrical(BinaryTreeNode* pRoot)
{
	return isSymmertrical(pRoot,pRoot);
}

bool isSymmertrical(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2)
{
	if(pRoot1==nullptr && pRoot2==nullptr)
		return true;
	if(pRoot1==nullptr || pRoot2==nullptr)
		return false;

	if(pRoot1->m_nValue!=pRoot2->m_nValue)
		return false;

	return isSymmertrical(pRoot1->m_pLeft,pRoot2->m_pRight) && isSymmertrical(pRoot1->m_pRight,pRoot2->m_pLeft);
}
