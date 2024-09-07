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

Node* removeDuplicatesFromLinkedList(Node* &head){
    Node* curr=head;
    while(curr!=NULL){
        if(curr->next!=NULL && curr->next->data==curr->data){
            curr->next=curr->next->next;
        }
        else{
            curr=curr->next;
        }
    }
    return head;
}

Node* removeDuplicatesFromSortedLinkedList(Node* head){
    Node* curr=head;
    Node* prev=NULL;
    while (curr!=NULL){
        int cnt=0;
        Node* forward=curr;
        Node* pointerBeforeForward=NULL;
        int value=curr->data;
        while(value==forward->data){
            pointerBeforeForward=forward;
            curr=curr->next;
            forward=forward->next;
            cnt++;
        }
        cout<<curr->data<<"-"<<cnt<<endl;
        // curr=curr->next;
    }
    return head;
}

int main(){
    Node* head=new Node(1);
    Node* tail=head;
    insertAtTail(tail,2);
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,3);
    print(head);
    // removeDuplicatesFromLinkedList(head);
    // print(head);
    head=removeDuplicatesFromSortedLinkedList(head);
    print(head);
    return 0;
}