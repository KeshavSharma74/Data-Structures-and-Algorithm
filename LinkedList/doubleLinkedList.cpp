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

void insertAtTailing(Node* &head,Node* &tail,int data){
    Node* temp=new Node(data);
    if(head==NULL){
        head=temp;
        tail=temp;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}


Node* reverseLinkedList(Node* head){
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

Node* multiply(Node* head){
    Node* heading=NULL;
    Node* tail=NULL;
    int carry=0,ans=0;
    while(head!=NULL){
        ans=head->data*2+carry;
        int digit=ans%10;
        carry=ans/10;
        insertAtTailing(heading,tail,digit);
        head=head->next;
    }
    while (carry!=0)
    {
        insertAtTailing(heading,tail,carry);
        carry=carry/10;
    }
    return heading;
}



Node* multiplyByTwo(Node* head){
    head=reverseLinkedList(head);
    head=multiply(head);
    head=reverseLinkedList(head);
    return head;
}

int main(){
    Node* head=new Node(9);
    Node* tail=head;
    insertAtTail(tail,9);
    insertAtTail(tail,9);
    print(head);
    Node* ans=multiplyByTwo(head);
    print(ans);
    return 0;
}