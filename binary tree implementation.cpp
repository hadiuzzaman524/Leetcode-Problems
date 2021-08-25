#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left,*right;
    Node(int data)
    {
        this->data=data;
        left=right=nullptr;
    }
};
void addLeft(Node *root, Node *child){
    root->left=child;
}
void addRight(Node *root, Node *child){
root->right=child;
}

void inOrder(Node *root){

   stack<Node *> stk;
   Node *temp= root;

   while(temp!=nullptr || !stk.empty()){

        while(temp!=nullptr){
            stk.push(temp);
            temp=temp->left;
        }

        temp=stk.top();
        stk.pop();
        cout<< temp->data<< " ";

        temp=temp->right;
   }

}
void preOrder(Node *root){

    if(root==nullptr)
        return;

    stack<Node*> stk;
    stk.push(root);
    Node *temp;

    while(!stk.empty()){
        temp= stk.top();
        cout<< temp->data<<" ";
        stk.pop();

        if(temp->right){
            stk.push(temp->right);
        }

        if(temp->left){
            stk.push(temp->left);
        }
    }

}

void postOrder(Node *root){

    stack<Node *> stk1;
    stack<Node *> stk2;

    Node *temp=root;

    stk1.push(temp);

    while(!stk1.empty()){
        temp= stk1.top();
        stk1.pop();
        stk2.push(temp);

        if(temp->left)
            stk1.push(temp->left);
        if(temp->right)
            stk1.push(temp->right);
    }

    while(!stk2.empty()){
        cout<< stk2.top()-> data<< " ";
        stk2.pop();
    }
}

int main()
{
    Node *root=new Node(2);
    addLeft(root,new Node(3));
    addRight(root, new Node(7));
    addLeft(root->left, new Node(4));
    addLeft(root->left->left, new Node(6));
    addRight(root->left,new Node(5));

    inOrder(root);
    cout<<endl<< "PreOrder Traversal Using Stack: "<<endl;
    preOrder(root);
    cout<<endl;
    postOrder(root);


    return 0;
}
