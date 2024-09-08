#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
};

void print(Node* head){
    for(;head;head=head->next)  cout<<head->data<<"->";
    cout<<"NULL"<<endl;
}

void insertAtTail(Node* &tail,int data){
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
}

Node* reverseLinkedList(Node* &head){
    Node* curr=head;
    Node* prev=NULL;
    Node* forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

Node* middleNode(Node* head){
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

bool isPalindrome(Node* head){
    if(head==NULL || head->next==NULL)  return true;
    Node* mid=middleNode(head);
    Node* temp=reverseLinkedList(mid->next);
    Node* head1=head;
    Node* head2=temp;
    while(head2!=NULL){
        if(head1->data!=head2->data)    return false;
        head1=head1->next;
        head2=head2->next;
    }
    return true;
}

int main(){
    Node* head=new Node(1);
    Node* tail=head;
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    insertAtTail(tail,2);
    insertAtTail(tail,1);
    print(head);
    cout<<isPalindrome(head)<<endl;
    return 0;
}