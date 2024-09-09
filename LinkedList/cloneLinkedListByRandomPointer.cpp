#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* random;
        Node(int data){
            this->data=data;
            this->next=NULL;
            this->random=NULL;
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

Node* cloneLinkedList(Node* head){
    Node* cloneHead=NULL;
    Node* cloneTail=NULL;
    Node* temp=head;
    while(temp!=NULL){
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp=temp->next;
    }

    unordered_map<Node*,Node*> oldToNew;
    Node* originalNode=head;
    Node* cloneNode=cloneHead;
    while(temp!=NULL){
        oldToNew[originalNode]=cloneNode;
        originalNode=originalNode->next;
        cloneNode=cloneNode->next;
    }

    cloneNode=cloneHead;
    originalNode=head;
    while(cloneNode!=NULL){
        cloneNode->random=oldToNew[originalNode->random];
    }
    return cloneNode;
}

    Node* copyRandomList(Node* head) {
        Node* cloneTail=NULL;
        Node* cloneHead=NULL;
        Node* temp=head;
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp=temp->next;
        }

        Node* originalNode=head;
        Node* cloneNode=cloneHead;
        while(originalNode!=NULL && cloneNode!=NULL){
            Node* forward=originalNode->next;
            originalNode->next=cloneNode;
            originalNode=forward;
            forward=cloneNode->next;
            cloneNode->next=originalNode;
            cloneNode=forward;
        }

        temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL){
                if(temp->random!=NULL){
                    temp->next->random=temp->random->next;
                }
                else{
                    temp->next->random=temp->random;
                }
            }
            temp=temp->next->next;
        }

        originalNode=head;
        cloneNode=cloneHead;
        while(originalNode!=NULL && cloneNode!=NULL){
            originalNode->next=cloneNode->next;
            originalNode=originalNode->next;
            if(originalNode!=NULL){
                cloneNode->next=originalNode->next;
            }
            cloneNode=cloneNode->next;
        }
        return cloneHead;
    }

int main(){
    Node* head=new Node(7); 
    Node* tail=head;
    insertAtTail(head,tail,13);
    insertAtTail(head,tail,11);
    insertAtTail(head,tail,10);
    insertAtTail(head,tail,1); 
    head->random=NULL;
    head->next->random=head;
    head->next->next->random=head->next->next->next->next;
    head->next->next->next->random=head->next->next;
    head->next->next->next->next->random=head->next->next;
    print(head); 
    return 0;
}