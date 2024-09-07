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

Node* floydsDetectionAlgorithm(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)  return slow;
    }
    return NULL;
}

Node* floydsDetectionBegging(Node* head){
    if(head==NULL)  return NULL;
    Node* intersection=floydsDetectionAlgorithm(head);
    if(intersection==NULL)  return NULL;
    Node* slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
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
    tail->next=head->next->next;
    cout<<floydsDetectionBegging(head)->data<<endl;
    // print(head);

    return 0;
}