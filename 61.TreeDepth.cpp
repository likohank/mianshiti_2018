int TreeDepth(BinaryTreeNode* pRoot)
{
	if(pRoot==nullptr)
		return 0;

	int left = TreeDepth(pRoot->m_pLeft);
	int right = TreeDepth(pRoot->m_pRight);

	return left>right?(left+1):(right+1);
}

bool IsBalance(BinaryTreeNode* pRoot)
{
	int depth = 0;
	return IsBalanceCore(pRoot,&depth);
}

bool IsBalanceCore(BinaryTreeNode* pRoot,int* depth)
{
	if(pRoot==nullptr)
	{
		*depth = 0;
		return true;
	}

	int left=0;
	int right=0;

	if( IsBalanceCore(pRoot->m_pLeft,&left) && IsBalanceCore(pRoot->m_pRight,&right) )
	{
		diff = left-right;
		if(diff<=1 && diff>=-1)
		{
			*depth =1+ ( (left>right)>left:right );
			return true;
		}
	}
	return false;
}
