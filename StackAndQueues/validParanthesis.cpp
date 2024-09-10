#include<bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string s)
{
    stack<char> st;
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        if(ch=='{' || ch=='(' || ch=='['){
            st.push(ch);
        }
        else{
            if(!st.empty()){
                char peek=st.top();
                if( (ch=='}' && peek=='{') || (ch==')' && peek=='(') || (ch==']' && peek=='[') ){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(st.empty())  return true;
    else return false;
}

int main(){
    string str="{[({})]}";
    if(isValidParenthesis(str)){
        cout<<"Paranthesis is Valid"<<endl;
    }
    else{
        cout<<"Paranthesis is not valid"<<endl;
    }
    return 0;
}