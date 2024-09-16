#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q1,q2;
    MyStack() { }

    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        if(q1.empty()){
            return -1;
        }
        else{
            int ans=q1.front();
            q1.pop();
            return ans;
        }
    }
    
    int top() {
        if(q1.empty()){
            return -1;
        }
        else{
            return q1.front();
        }
    }
    
    bool empty() {
        if(q1.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};



int main(){
    
    return 0;
}