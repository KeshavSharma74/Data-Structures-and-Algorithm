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

class Queue{
    public:
        Node* front;
        Node* rear;
        Queue(){
            front=NULL;
            rear=NULL;
        }
        void enqueue(int data){
            Node* temp=new Node(data);
            if(rear==NULL){
                rear=front=temp;
                return;
            }
            else{
                rear->next=temp;
                rear=temp;
            }
        }
        void dequeue(){
            if(front==NULL){
                cout<<"Queue is Empty"<<endl;
                return;
            }
            else{
                front=front->next;
                if(front==NULL){
                    front=rear=NULL;
                }
            }
        }
        bool isEmpty(){
            return front==NULL;
        }
        void display(){
            if(front==NULL){
                return;
            }
            Node* temp=front;
            for(;temp;temp=temp->next){
                cout<<temp->data<<" ";
            }
            cout<<endl; 
        }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}