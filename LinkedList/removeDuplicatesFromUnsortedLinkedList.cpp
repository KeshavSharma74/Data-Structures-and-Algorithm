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

Node *removeDuplicates(Node *head)
{
    Node* prev=NULL;
    Node* curr=head;
    unordered_map<int,bool> m;
    while(curr!=NULL){
        if(m[curr->data]==true){  
            prev->next=curr->next;
            Node* nodeToDelete=curr;
            delete curr;
            curr=prev->next;
        }
        else{
            m[curr->data]=true;
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
}

int main(){
    Node* head=new Node(3);
    Node* tail=head;
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    print(head);
    return 0;
}