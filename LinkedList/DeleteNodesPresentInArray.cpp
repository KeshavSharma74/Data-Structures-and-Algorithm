#include<bits/stdc++.h>
using namespace std;

class Node{
    public :
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

void deleteNode(Node* head,vector<int> nums){
    
}

int main(){
    Node* head=new Node(1);
    Node* tail=head;
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    insertAtTail(tail,5);
    print(head);
    vector<int> nums={1,2,3};
    return 0;
}