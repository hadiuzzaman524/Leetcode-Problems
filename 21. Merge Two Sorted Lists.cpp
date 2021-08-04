#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution
{
public:

    void insertData(int x, ListNode *head)
    {

        while(head->next!=nullptr)
        {
            head=head->next;

        }
        head->next=new ListNode;
        head->next->val=x;
        head->next->next=nullptr;

    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {

        ListNode *head=new ListNode();
        head->next=nullptr;


        while(l1->next!=nullptr||l2->next!=nullptr)
        {

            int first=l1->next->val;
            int second=l2->next->val;

            if(first<=second)
            {
                insertData(first,head);
                insertData(second,head);
            }
            else if(second<=first)
            {

                insertData(second,head);
                insertData(first,head);
            }
            l1=l1->next;
            l2=l2->next;
            if(l1->next==nullptr||l2->next==nullptr)
            {
                break;
            }


        }
        while(l1->next!=nullptr)
        {
            int data=l1->next->val;
            insertData(data,head);
            l1=l1->next;

        }
        while(l2->next!=nullptr)
        {
            int data=l2->next->val;
            insertData(data,head);
            l2=l2->next;

        }

        return head;
    }
};
void display(ListNode *head)
{

    while(head->next!=nullptr)
    {
        cout<< head->next->val<< " ";
        head=head->next;
    }
}


int main()
{
    Solution obj;
    ListNode *head=new ListNode;
    head->next=nullptr;

    obj.insertData(2,head);

    //display(head);


    ListNode *head2=new ListNode;
    head2->next=nullptr;

    obj.insertData(1,head2);

    //display(head2);

    ListNode *node=obj.mergeTwoLists(head,head2);
    display(node);

    return 0;
}
