struct BinaryTreeNode
{
	double 	m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_Right;
};

bool HasSubTree(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2)
{
	bool result = false;
	if(pRoot1 == nullptr && pRoot2==nullptr)
	{
		if(Equal(pRoot1->m_nValue,pRoot2->m_nValue))
			result = DoesTree1HasTrees2(pRoot1,pRoot2);
		if(!result)
			result = HasSubTree(pRoot1->m_pLeft,pRoot2);
		if(!result)
			result = hasSubTree(pRoot1->m_Right,pRoot2);
	}
	return result;
}

bool DoesTree1HaTree2(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2)
{
	bool result = false;
	if(pRoot1==nullptr)
		return false;
	if(pRoot2==nullptr)
		return true;

	if(Equal(pRoot1->m_nValue,pRoot2->m_nValue))
		result = true;
	if(result)
		DoesTree1HasTree2(pRoot1->m_pLeft,pRoot2->m_pLeft);
	if(result)
		Doestree1HasTree2(pRoot1->m_pLeft,pRoot2->m_pRight);
	return result;
}
