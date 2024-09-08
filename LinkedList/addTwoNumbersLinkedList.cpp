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

void insertAtTail(Node* &head,Node* &tail,int data){
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

Node* add(Node* first,Node* second){
    int carry=0,sum=0;
    Node* head=NULL;
    Node* tail=NULL;
    while(first!=NULL && second!=NULL){
        sum=first->data+second->data+carry;
        int digit=sum%10;
        carry=sum/10;
        insertAtTail(head,tail,digit);
        first=first->next;
        second=second->next;
    }
    while(first!=NULL){
        sum=first->data+carry;
        int digit=sum%10;
        carry=sum/10;
        insertAtTail(head,tail,digit);
        first=first->next;
    }
    while(second!=NULL){
        sum=second->data+carry;
        int digit=sum%10;
        carry=sum/10;
        insertAtTail(head,tail,digit);
        second=second->next;
    }
    while(first!=NULL && second!=NULL){
        sum=first->data+second->data+carry;
        int digit=sum%10;
        carry=sum/10;
        insertAtTail(head,tail,digit);
    }
    return head;
}

Node* addition(Node* first,Node* second){
    Node* head=NULL;
    Node* tail=NULL;
    int carry=0,sum=0;
    while(first!=NULL || second!=NULL || carry!=0){
        int value1=0;
        if(first!=NULL)     value1=first->data;
        int value2=0;
        if(second!=NULL)    value2=second->data;
        sum=value1+value2+carry;
        int digit=sum%10;
        carry=sum/10;
        insertAtTail(head,tail,digit);
        if(first!=NULL)     first=first->next;
        if(second!=NULL)    second=second->next;
    }
    return head;
}

Node* addToNumbers(Node* head1,Node* head2){
    if(head1==NULL)     return head2;
    if(head2==NULL)     return head1;
    Node* first=reverseLinkedList(head1);
    Node* second=reverseLinkedList(head2);
    Node* head=addition(first,second);
    head=reverseLinkedList(head);
    return head;
}

int main(){
    Node *head1 = new Node(1);
    Node *tail1 = head1;
    insertAtTail(head1,tail1, 2);
    insertAtTail(head1,tail1, 4);
    print(head1);

    Node *head2 = new Node(1);
    Node *tail2 = head2;
    insertAtTail(head2,tail2, 3);
    insertAtTail(head2,tail2, 4);
    print(head2);
    Node* head=addToNumbers(head1,head2);
    print(head);
    return 0;
}