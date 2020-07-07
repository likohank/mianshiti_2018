#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class TreeNode
{
public:
    int mValue;
    TreeNode *mLeft;
    TreeNode *mRight;

    TreeNode(int value)
    {
        mValue = value;
        mLeft = NULL;
        mRight = NULL;
    }
};

void connectTreeNodes(TreeNode *root, TreeNode *left, TreeNode *right)
{
    if (root != NULL) {
        root->mLeft = left;
        root->mRight = right;
    }
}

void preOrderTree(const TreeNode *root) // root, left, right
{
    if (root == NULL) {
        return;
    }
    cout << root->mValue << endl;
    preOrderTree(root->mLeft);
    preOrderTree(root->mRight);
}

void inOrderTree(const TreeNode *root)  // left, root, right
{
    if (root == NULL) {
        return;
    }
    inOrderTree(root->mLeft);
    cout << root->mValue << endl;
    inOrderTree(root->mRight);
}

void postOrderTree(const TreeNode *root)    // left, right, root
{
    if (root == NULL) {
        return;
    }
    postOrderTree(root->mLeft);
    postOrderTree(root->mRight);
    cout << root->mValue << endl;
}

void preOrderTree2(const TreeNode *root)
{
    const TreeNode *node = root;
    stack<const TreeNode *> st;
    while (node != NULL || !st.empty()) {
        while (node != NULL) {
            cout << node->mValue << endl;
            st.push(node);
            node = node->mLeft;
        }
        if (!st.empty()) {
            node = st.top();
            st.pop();
            node = node->mRight;
        }
    }
}

void inOrderTree2(const TreeNode *root)
{
    const TreeNode *node = root;
    stack<const TreeNode *> st;
    while (node != NULL || !st.empty()) {
        while (node != NULL) {
            st.push(node);
            node = node->mLeft;
        }
        if (!st.empty()) {
            node = st.top();
            st.pop();
            cout << node->mValue << endl;
            node = node->mRight;
        }
    }
}


void postOrderTree2(const TreeNode *root)
{
    const TreeNode *node = root;
    const TreeNode *pLast = root;
    stack<const TreeNode*> st;
    while (node != NULL || !st.empty()) {
        //while (node != NULL) {
        if (node != NULL) {
            st.push(node);
            node = node->mLeft;
        }
        //if (!st.empty()) {
        else {
            node  = st.top();
            if (node->mRight == NULL || node->mRight==pLast) {
                st.pop();
                cout << node->mValue << endl;
		pLast = node;
                node = NULL;
            } else {
                node = node->mRight;
            }
        }
    }
}

/*
void postOrderTree2(const TreeNode *root)
{
    stack<const TreeNode*> st;
    const TreeNode *current = NULL;
    const TreeNode *pre = root;
    st.push(root);

    while (!st.empty()) {
        current = st.top();
        if ((current->mLeft == NULL && current->mRight == NULL) || current->mLeft == pre || current->mRight == pre) {
            cout << current->mValue << endl;
            st.pop();
            pre = current;
        } else {
            if (current->mRight != NULL) {
                st.push(current->mRight);
            }
            if (current->mLeft != NULL) {
                st.push(current->mLeft);
            }
        }
    }
}
*/

TreeNode* createTree()
{
    TreeNode *p = new TreeNode(1);
    TreeNode *root = p;
    TreeNode *pleft = new TreeNode(2);
    TreeNode *right = new TreeNode(3);
    connectTreeNodes(p, pleft, right);
    
    TreeNode *ppl = new TreeNode(4);
    TreeNode *ppr = new TreeNode(5);
    connectTreeNodes(pleft, ppl, ppr);
    
    ppr = new TreeNode(6);
    connectTreeNodes(right, NULL, ppr);
    p = new TreeNode(7);
    connectTreeNodes(ppr, p, NULL);
    
    return root;
}

int main()
{
    TreeNode *p = createTree();
    
    cout << "postOrder: " << endl;
    postOrderTree(p);

    cout << "postOrder2: " << endl;
    postOrderTree2(p);
    return 0;
}
