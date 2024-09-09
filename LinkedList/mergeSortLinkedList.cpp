#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
        int val;
        ListNode* next;
        ListNode(int val){
            this->val=val;
            this->next=NULL;
        }
};

void print(ListNode* head){
    for(;head;head=head->next)   cout<<head->val<<"->";
    cout<<"NULL"<<endl;
}

void insertAtTail(ListNode* &tail,int data){
    ListNode* temp=new ListNode(data);
    tail->next=temp;
    tail=temp;
}

ListNode* middleNode(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

ListNode* merge(ListNode* left,ListNode* right){
    if(left==NULL)  return right;
    if (right==NULL)    return left;

    ListNode* ans=new ListNode(-1);
    ListNode* temp=ans;

    while(left!=NULL && right!=NULL){
        if(left->val<right->val){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else{
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }
    while(left!=NULL){
        temp->next=left;
        temp=left;
        left=left->next;
    }
    while(right!=NULL){
        temp->next=right;
        temp=right;
        right=right->next;
    }

    ans=ans->next;
    return ans;
}

ListNode* mergeSort(ListNode* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    ListNode* mid=middleNode(head);
    ListNode* left=head;
    ListNode* right=mid->next;
    mid->next=NULL;

    left=mergeSort(left);
    right=mergeSort(right);
    ListNode* result=merge(left,right);

    return result;
}

int main(){
    ListNode* head=new ListNode(4);
    ListNode* tail=head;
    insertAtTail(tail,2);
    insertAtTail(tail,1);
    insertAtTail(tail,3);
    print(head);
    head=mergeSort(head);
    print(head);
    return 0;
}