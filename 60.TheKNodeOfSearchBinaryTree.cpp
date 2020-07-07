BinaryTreeNode* KthOfTree(BinaryTreeNode* pRoot,unsigned int k)
{
	if(pRoot==nullptr || k==0)
		return nullptr;

	return KthOfTreeCore(pRoot,k);
}

BinaryTreeNode* KthOfTreeCore(BinaryTreeNode* pRoot,unsigned int& k)
{
	BinaryTreeNode target = nullptr;

	if(pRoot->m_pLeft!=nullptr)
		target = KthOfTreeCore(pRoot->m_Left,k);

	if(target==nullptr)
	{
		if(k==1)
			target = pRoot;
		k--;
	}

	if(target==nullptr && pRoot->m_pRight!=nullptr)
		target = KthOfTreeCore(pRoot->m_pRight,k);

	return target;
}
