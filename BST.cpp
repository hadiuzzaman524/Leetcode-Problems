#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right, *parent;

    Node(int data)
    {
        this->data=data;
        left=right=parent=nullptr;
    }

};



Node *insertBST(Node *root, int data)
{
    Node *temp=new Node(data);

    if(root==nullptr)
    {
        root=temp;
        return root;
    }

    Node *r=nullptr,*t=root;

    while(t!=nullptr)
    {
        r=t;

        if(data==t->data)
            return root;

        if(data< t->data)
        {

            t=t->left;
        }
        else if(data> t->data)
        {

            t=t->right;
        }
    }

    if(r->data > data)
    {
        r->left= temp;
    }
    if(r->data< data)
    {
        r->right= temp;
    }
    return root;

}

Node *insertBST_R(Node *root, int value)
{

    if(root==nullptr)
    {
        return new Node(value);
    }

    if(value> root->data)
    {
        root->right= insertBST_R(root->right, value);

    }
    else if(value< root->data)
    {
        root->left= insertBST_R(root->left, value);
    }

    return root;
}
void inOrder(Node *root)
{

    if(root==nullptr)
        return;
    if(root->left)
        inOrder(root->left);
    cout<< root->data<< " ";
    if(root->right)
        inOrder(root->right);
}

int main()
{
    int arr[]= {30,24,26,40,46,50};
    Node *root=new Node();

    for(int x: arr){
        root= insertBST_R(root, x);
    }


    inOrder(root);
    return 0;
}
