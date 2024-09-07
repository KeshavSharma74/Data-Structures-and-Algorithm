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

void print(Node *head){
    for(;head;head=head->next)  cout<<head->data<<"->";
    cout<<"NULL"<<endl;
}

void insertAtTail(Node* &tail,int data){
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
}

Node* sort0s1s2s(Node* head){
    int zeroCnt=0,oneCnt=0,twoCnt=0;
    Node* temp=head;
    for(;temp;temp=temp->next){
        if(temp->data==0)   zeroCnt++;
        else if(temp->data==1)  oneCnt++;
        else twoCnt++;
    }

    temp=head;
    for(;temp;temp=temp->next){
        if(zeroCnt!=0){
            temp->data=0;
            zeroCnt--;
        }
        else if(oneCnt!=0){
            temp->data=1;
            oneCnt--;
        }
        else{
            temp->data=2;
            twoCnt--;
        }
    }
    return head;
}

void insertAtTailByPointer(Node* &tail,Node* curr){
    tail->next=curr;
    tail=curr;
}

Node* sort012(Node* head){

    Node* zeroHead=new Node(-1);
    Node* oneHead=new Node(-1);
    Node* twoHead=new Node(-1);
    
    Node* zeroTail=zeroHead;
    Node* oneTail=oneHead;
    Node* twoTail=twoHead;

    Node* curr=head;
    while(curr!=NULL){
        int value=curr->data;
        if(value==0)    insertAtTailByPointer(zeroTail,curr);
        else if(value==1)   insertAtTailByPointer(oneTail,curr);
        else  insertAtTailByPointer(twoTail,curr);
        curr=curr->next;
    }

    if(oneTail->next!=NULL){
        zeroTail->next=oneHead->next;
    }
    else{
        zeroTail->next=twoHead->next;
    }

    oneTail->next=twoHead->next;
    twoTail->next=NULL;
    head=zeroHead->next;
    
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}

int main(){
    Node* head=new Node(1);
    Node* tail=head;
    insertAtTail(tail,0);
    insertAtTail(tail,2);
    insertAtTail(tail,1);
    insertAtTail(tail,2);
    print(head);
    head=sort012(head);
    print(head);
    return 0;
}