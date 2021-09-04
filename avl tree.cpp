#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode *left, *right;
    int height;
    int val;

    TreeNode(int val)
    {
        this->val=val;
        height=0;
        left=right=nullptr;
    }
};

int maximum(int a, int b)
{
    return a>b? a:b;
}

int height(TreeNode *root)
{
    if(root==nullptr)
        return -1;
    return root->height;
}
TreeNode *RR(TreeNode *root)
{
    TreeNode *x= root->left;
    TreeNode *m= x->right;

    x->right= root;
    root->left= m;

    x->height= maximum(height(x->left), height(x->right))+1;
    root->height= maximum(height(root->left), height(root->right))+1;

    return x;
}

TreeNode *LR(TreeNode *root)
{

    TreeNode *x= root->right;
    TreeNode *m= x->left;

    x->left= root;
    root->right=m;

    x->height= maximum(height(x->left), height(x->right))+1;
    root->height= maximum(height(root->left), height(root->right))+1;

    return x;

}

int getBalance(TreeNode *root)
{
    if(root==nullptr)
        return 0;
    return height(root->left)- height(root->right);
}

TreeNode *insertAVL(TreeNode *root, int val)
{
    if(root==nullptr)
        return new TreeNode(val);

    if(val < root->val)
        root->left= insertAVL(root->left, val);
    if(val> root->val)
        root->right= insertAVL(root->right, val);

    else
        return root;

    root->height= 1+ maximum(height(root->left), height(root->right));

    int bf= getBalance(root);

    //LL
    if(bf > 1 && val < root->left->val)
    {

        return RR(root);
    }
    //RR
    if(bf < -1 && val > root->right->val)
    {
        return LR(root);
    }
    //LR
    if(bf> 1 && val> root->left->val)
    {
        root->left= LR(root->left);
        return RR(root);
    }

    //RL

    if(bf < -1 && val < root->right->val)
    {
        root->right= RR(root->right);
        return LR(root);
    }

    return root;

}

void inOrder(TreeNode *root)
{

    if(root==nullptr)
        return;
    inOrder(root->left);
    cout<< root->val<< " ";
    inOrder(root->right);

}
int main()
{
    TreeNode *root = nullptr;

    /* Constructing tree given in
    the above figure */
    root = insertAVL(root, 10);
    root = insertAVL(root, 20);
    root = insertAVL(root, 30);
    root = insertAVL(root, 40);
    root = insertAVL(root, 50);
    root = insertAVL(root, 25);

    inOrder(root);
    return 0;
}
