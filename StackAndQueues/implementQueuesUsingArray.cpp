#include<bits/stdc++.h>
using namespace std;

class Queue{
    private:
        int qfront;
        int rear;
        int *arr;
        int size;
    public:
        Queue(){
            size=100001;
            arr=new int[size];
            qfront=0;
            rear=0;
        }
        bool isEmpty(){
            if(qfront==rear){
                return true;
            }
            else{
                return false;
            }
        }
        void enqueue(int data){
            if(rear==size){
                return;
            }
            else{
                arr[rear]=data;
                rear++;
            }
        }
        int dequeue(){
            if(rear==qfront){
                return -1;
            }
            else{
                int value=arr[qfront];
                arr[qfront]=-1;
                qfront++;
                if(qfront==rear){
                    rear=0;
                    qfront=0;
                }
                return value;
            }
        }
        int front(){
            if(qfront==rear){
                return -1;
            }
            else{
                return arr[qfront];
            }
        }
};

int main(){
    
    return 0;
}