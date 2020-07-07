#include<cstdio>
#include<cstring>

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* Construct( int* preOrder,int* inOrder,int length)
{
	if(preOrder == nullptr || inOrder==nullptr || length<0)
		return nullptr;
	return ConstructCore(preOrder,preOrder+length-1,inorder,inorder+length-1);
}

BinaryTreeNode* ConstructCore(int* startPreorder,int* endPreorder,int* startInorder,int* endInorder)
{
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();

	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;

	if(startPreorder == endPreorder)
	{
		if(startInorder==endInorder && *startInorder==*endInorder)
			return root;
		else
		{
			throw std::exception("Wrong Number");
		}
	}

	int* rootInorder = startInorder;
	while(rootInorder<endInorder && *rootInorder!=root->m_Value)
		++rootInorder;

	if(rootInorder==endInorder && rootInorder->m_nValue!=endInorder->m_nValue)
		throw std::exception(Wrong Number);

	int length = rootInorder-startInorder;

	if(length>0)
		root->m_pLeft = ConstructCore(startPreorder+1,startPreorder+length,startInorder,startInorder+length-1);
	if(endInorder-rootInorder>0)
		root->m_pright = ConstructCore(startPreorder+length+1,endPreorder,rootInorder+1,endInorder);

	return root;
}

int main()
{

}
