#include <bits/stdc++.h>
using namespace std;

class ListNode{

public:
    int val;
    ListNode *next;
};

int main(){

    ListNode *node=new ListNode();
    node->val=10;
    node->next=nullptr;

    while(node!=nullptr){
        cout<< node->val<<endl;
        node=node->next;
    }

    cout<< *node.val;
return 0;
}
