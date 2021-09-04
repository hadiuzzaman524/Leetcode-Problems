#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode *left, *right;
    int val;

    TreeNode(int val)
    {
        this->val= val;
        left=right=nullptr;
    }

};

TreeNode *insertBST(TreeNode *root, int key)
{

    if(root==nullptr)
        return new TreeNode(key);

    if(key < root->val)
        root->left= insertBST(root->left, key);
    else
        root->right= insertBST(root->right, key);

    return root;
}

void inOrder(TreeNode *root)
{

    if(root==nullptr)
        return;

    inOrder(root->left);
    cout<< root->val<<" ";
    inOrder(root->right);

}

TreeNode *findMin(TreeNode *root)
{

    if(root==nullptr)
        return root;
    while(root->left!=nullptr)
    {
        root=root->left;
    }
    return root;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if(root==nullptr)
        return root;

    if(key< root->val)
        root->left= deleteNode(root->left, key);
    else if(key> root->val)
    {
        root->right= deleteNode(root->right, key);
    }
    else
    {
        // have no children
        if(root->left==nullptr && root->right==nullptr)
            return nullptr;

        if(root->left==nullptr){
            TreeNode *temp= root->right;
            delete(root);
            return temp;
        }

        if(root->right==nullptr){
            TreeNode *temp= root->left;
            delete(root);
            return temp;
        }

            TreeNode *successor= findMin(root->right);

            root->val= successor->val;

            root->right= deleteNode(root->right, successor->val);


        return root;

    }
}

int main()
{
    TreeNode* root = nullptr;
    root = insertBST(root, 50);
    root = insertBST(root, 30);
    root = insertBST(root, 20);
    root = insertBST(root, 40);
    root = insertBST(root, 70);
    root = insertBST(root, 60);
    root = insertBST(root, 80);

    cout<< "Create A Binary Tree: ";
        inOrder(root);
    cout<< endl;

    cout<< "After Deletion: ";
    deleteNode(root,20);
    deleteNode(root,30);
    deleteNode(root,50);
    inOrder(root);
    cout<<endl;

    return 0;
}
