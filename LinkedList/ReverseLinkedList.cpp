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
    Node* temp=head;
    for(;head;head=head->next)  cout<<head->data<<"->";
    cout<<"NULL"<<endl;
}

void insertAtTail(Node* &tail,int data){
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
}

Node* reverseLinkedListUsingLoop(Node* head){
    Node* prev=NULL;
    Node* forward=NULL;
    Node* curr=head;
    while(curr!=NULL){
        Node* forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

void reverseLinkedListUsingRecursion(Node* &head,Node* prev,Node* curr){
    if(curr==NULL){
        head=prev;
        return;
    }
    reverseLinkedListUsingRecursion(head,curr,curr->next);
    curr->next=prev;
}
 
Node* reverseLinkedListUsingRecursionII(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* smallHead=reverseLinkedListUsingRecursionII(head->next);
    head->next->next=head;
    head->next=NULL;
    return smallHead;
}

int main(){
    Node* head=new Node(10);
    Node* tail=head;
    insertAtTail(tail,11);
    insertAtTail(tail,12);
    insertAtTail(tail,13);
    insertAtTail(tail,14);
    insertAtTail(tail,15);
    print(head);
    head=reverseLinkedListUsingLoop(head);
    print(head);
    reverseLinkedListUsingRecursion(head,NULL,head);
    print(head);
    head=reverseLinkedListUsingRecursionII(head);
    print(head);
    return 0;
}