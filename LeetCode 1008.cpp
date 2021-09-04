#include <bits/stdc++.h>
using namespace std;


class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:

    TreeNode* addBST(TreeNode *root, int x)
    {
        TreeNode *temp = new TreeNode(x);
        if(root==nullptr)
        {
            root=temp;
            return root;
        }

        TreeNode *parent= nullptr;
        TreeNode *current= root;

        while(current!=nullptr)
        {
            parent= current;

            if(x < current->val)
            {
                current= current->left;
            }
            else
            {
                current= current->right;
            }
        }

        if(x < parent->val)
        {
            parent->left= temp;
        }
        else
        {
            parent->right= temp;
        }

        return root;
    }



    TreeNode* bstFromPreorder(vector<int>& preorder)
    {

        TreeNode *root = new TreeNode(preorder[0]);

        for(int i=1; i< preorder.size(); i++)
        {
            root= addBST(root, preorder[i]);
        }

        return root;
    }
};
void inOrder(TreeNode *root)
{

    if(root==nullptr)
        return;
    if(root->left)
        inOrder(root->left);
    cout<< root->val<< " ";
    if(root->right)
        inOrder(root->right);
}

int main()
{
    Solution obj= Solution();
    vector<int> v= {8,5,1,7,10,12};

    TreeNode *ptr=obj.bstFromPreorder(v);
    inOrder(ptr);
    return 0;
}
