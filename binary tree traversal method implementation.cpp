#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data=data;
        left=right=nullptr;
    }
};

void addLeft(Node *root, Node *child)
{
    root->left= child;

}

void addRight(Node *root, Node *child)
{
    root->right=child;
}

void preOrderRecursive(Node *root)
{

    if(root==nullptr)
        return;

    if(root->left)
        preOrderRecursive(root->left);
    if(root->right)
        preOrderRecursive(root->right);
    cout<< root->data<< " ";
}

void preOrderIterative(Node *root)
{

    stack<Node*> stk;
    Node *temp;


    if(root==nullptr)
        return;
    stk.push(root);

    while(!stk.empty())
    {

        temp= stk.top();
        stk.pop();
        cout<< temp->data<< " ";

        if(temp->right)
            stk.push(temp->right);
        if(temp->left)
            stk.push(temp->left);
    }

}
void inOrderTraverseIterative(Node *root)
{

    if(root==nullptr)
        return;

    stack<Node *> stk;
    Node *temp= root;

    while(temp!=nullptr || !stk.empty())
    {

        while(temp !=nullptr)
        {
            stk.push(temp);
            temp=temp->left;
        }

        temp= stk.top();
        stk.pop();
        cout<< temp->data<< " ";

        temp=temp->right;
    }
}

void postOrderTraversalIterative(Node *root)
{

    stack<Node *> stk1;
    stack<Node *> stk2;

    stk1.push(root);
    Node *temp;


    while(!stk1.empty())
    {
        temp= stk1.top();
        stk1.pop();
        stk2.push(temp);

        if(temp->left)
            stk1.push(temp->left);
        if(temp->right)
            stk1.push(temp->right);


    }

    while(!stk2.empty())
    {
        cout<< stk2.top()->data<< " ";
        stk2.pop();
    }

}

stack<int> stk;
stack<int> stk2;

void printStack()
{

    while(!stk.empty())
    {
        int top= stk.top();
        stk2.push(top);
        stk.pop();



    }
    while(!stk2.empty())
    {
        cout<< stk2.top()<< " ";
        stk.push(stk2.top());
        stk2.pop();
    }
    cout<<endl;
}

void printPath(Node *root)
{
    if(root==nullptr)
        return;

    stk.push(root->data);

    if(root->left)
        printPath(root->left);

    if(root->left==nullptr && root->right==nullptr)
        printStack();

    if(root->right)
        printPath(root->right);

    stk.pop();
}
int main()
{
    Node *root= new Node(2);
    addLeft(root, new Node(3));
    addRight(root, new Node (7));
    addLeft(root->left, new Node (4));
    addRight(root->left,new Node( 5));
    addLeft(root->left->left,new Node (6));
    preOrderRecursive(root);
    cout<<endl;
    preOrderIterative(root);
    cout<<endl;
    inOrderTraverseIterative(root);
    cout<<endl;
    postOrderTraversalIterative(root);
    cout<<endl<< "Path"<<endl;
    printPath(root);


    return 0;
}
