#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
        int top;
        int* arr;
        int size;
        Stack(int size){
            this->top=-1;
            arr=new int[size];
            this->size=size;
        }
        void push(int element){
            if(top<size-1){
                top++;
                arr[top]=element;
            }
            else{
                cout<<"Stack Overflow"<<endl;
            }
        }
        void pop(){
            if(top>=0){
                top--;
            }
            else{
                cout<<"Stack underflow"<<endl;
            }
        }
        int peek(){
            if(top>=0){
                return arr[top];
            }
            else{
                cout<<"Stack is Empty"<<endl;
                return -1;
            }
        }
        bool isEmpty(){
            if(top==-1){
                return true;
            }
            else{
                return false;
            }
        }
};

int main(){
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    return 0;
}