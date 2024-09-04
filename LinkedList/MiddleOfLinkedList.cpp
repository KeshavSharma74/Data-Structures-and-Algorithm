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

void insertAtTail(Node* &tail,int data){
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
}

void print(Node* head){
    for(;head;head=head->next)  cout<<head->data<<"->";
    cout<<"NULL"<<endl;
}

int length(Node* head){
    int cnt=0;
    for(;head;head=head->next){ 
        cnt++;
    }
    return cnt;
}

void middleOfLinkedList(Node* head){
    int len=length(head);
    // cout<<len<<endl;
    cout<<(len/2)+1<<endl;
}

Node* middleNode(Node* head){
    if(head==NULL || head->next==NULL)  return head;
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next; 
    }
    return slow;
}

int main(){
    Node* head=new Node(1);
    Node* tail=head;
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    insertAtTail(tail,5);
    insertAtTail(tail,6);
    print(head);
    middleOfLinkedList(head);
    Node* mid=middleNode(head);
    cout<<"Middle Node ->"<<mid->data;
    return 0;
}