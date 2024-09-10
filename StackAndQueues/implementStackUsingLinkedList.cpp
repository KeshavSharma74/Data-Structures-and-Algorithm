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

class Stack{
    private:
        Node* top;
        int size;
    public:
        Stack(){
            this->top=NULL;
            this->size=0;
        }
        bool isEmpty(){
            if(top==NULL){
                return true;
            }
            else{
                return false;
            }
        }
        void push(int data){
            Node* temp=new Node(data);
            temp->next=top;
            top=temp;
            size++;
        }
        void pop(){
            if(isEmpty()){
                cout<<"Stack UnderFlow"<<endl;
            }
            else{
                Node* temp=top;
                top=top->next;
                delete temp;
                size--;
            }
        }
        int peek(){
            if(isEmpty()){
                cout<<"Stack is Empty"<<endl;
                return -1;
            }
            else{
                return top->data;
            }
        }
        void display(){
            if(isEmpty()){
                cout<<"Stack is Empty"<<endl;
            }
            else{
                Node* temp=top;
                cout<<"Stack Elements : "<<endl;
                while(temp!=NULL){
                    cout<<temp->data<<" ";
                    temp=temp->next;
                }
                cout<<endl;
            }
        }
};

int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.display();
    st.pop();
    st.display();
    cout<<"ELEMENT AT PEEK : "<<st.peek();
    return 0;
}