void Seriallize(BinaryTreeNode* pRoot,ostream& stream)
{
	if(pRoot==nullptr)
	{
		stream<<"&,";
		return;
	}

	stream<<pRoot->m_nValue<<",";
	Seriallize(pRoot->m_pLeft,steam);
	Seriallize(pRoot->m_pRight,steam);
}

void Deserialize(BinaryTreeNode** pRoot,istream& stream)
{
	int number ;
	if(ReadStream(stream,&number))
	{
		*pRoot = new BinaryTreeNode();
		(*proot)->m_nValue = number;
		(*pRoot)->m_nLeft = (*pRoot)->nRight = nullptr;

		Deserialize((*pRoot)->m_pLeft,stream);
		Deserialize((*pRoot)->m_pRight,stream);
	}
}
