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


Node* reverseKGroups(Node* head,int k){
    int cnt=0;
    Node* curr=head;
    while(curr!=NULL && cnt<k){
        curr=curr->next;
        cnt++;
    }
    if(cnt==k){
        Node* prev=NULL;
        Node* forward=NULL;
        curr=head;
        int count=0;
        while(curr!=NULL && count<k){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count++;
        }
        if(forward!=NULL){
            head->next=reverseKGroups(forward,k);
        }
        return prev;
    }
    return head;
}

int main(){
    Node* head=new Node(1);
    Node* tail=head;
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    insertAtTail(tail,5);
    print(head);
    reverseKGroups(head,2);
    print(head);
    return 0;
}
