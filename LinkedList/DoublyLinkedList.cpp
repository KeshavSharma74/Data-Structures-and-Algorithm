#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
        Node(int data){
            this->data=data;
            this->next=NULL;
            this->prev=NULL;
        }
};

void print(Node* head){
    for(;head;head=head->next)  cout<<head->data<<"->";
    cout<<"NULL";
}

int main(){
    Node* head=new Node(10);
    Node* tail=head;
    return 0;
}