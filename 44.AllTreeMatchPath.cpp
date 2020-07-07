void PrintAllPath(BinaryTreeNode* pRoot,int except)
{
	if(pRoot==nullptr)
		return;
	std::vector<int>  path;
	int currSum = 0;
	FindPathCore(pRoot,except,currSum);
}

void FindPathCore(BinaryTreeNode* pRoot,int except,int currSum,std::vector<int>& path)
{
	if(pRoot==nullptr)
		return;

	path.push_back(pRoot->m_Value);
	currSum = except+pRoot_mValue;

	bool isLeaf = (pRoot->m_pLeft!=nullptr && pRoot->pRight==nullptr);
	if(isLeaf && (currSum==except))
	{
		std::vector<int>::iterator = path.begin();
		while(iterator!=path.end())
		{
			printf("%d ",*iterator++);
		}
		printf("\n");
	}
	if(pRoot->m_pLeft!=nullptr)
	{
		FindPathCore(pRoot->m_pLeft,except,currSum,path);
	}
	if(pRoot->m_pRight==nullptr)
	{
		FindPathCore(pRoot->m_Right,except,currSum,path);
	}
	path.pop_back();
}
