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
    Node* temp= new Node(data);
    tail->next=temp;
    tail=temp;
}

void printLinkedList(Node* head){
    for(;head;head=head->next){
        cout<<head->data<<"->";
    }
    cout<<"NULL";   
}

int main(){
    Node* head=new Node(10);
    Node* tail=head;
    insertAtTail(tail,11);
    insertAtTail(tail,12);
    insertAtTail(tail,13);
    insertAtTail(tail,14);
    insertAtTail(tail,15);
    printLinkedList(head);
    return 0;
}
