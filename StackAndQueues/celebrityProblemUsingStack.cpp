#include<bits/stdc++.h>
using namespace std;

bool knows(int a,int b,vector<vector<int>> arr){
    if(arr[a][b]==1){
        return true;
    }
    else{
        return false;
    }
}

int celebrity(vector<vector<int>> arr){
    stack<int> st;
    int n=arr.size();
    for(int i=0;i<n;i++){
        st.push(i);
    }
    while(st.size()>1){
        int a=st.top();
        st.pop();
        int b=st.top();
        st.pop();

        if(knows(a,b,arr)){
            st.push(b);
        }
        else{
            st.push(a);
        }
    }
    int ans=st.top();
    // rows
    bool rowCheck=true;
    for(int i=0;i<n;i++){
        if(arr[ans][i]==1 && i!=ans){
            return -1;
        }
    }
    // columns
    for(int i=0;i<n;i++){
        if(arr[i][ans]==0 && i!=ans){
            return -1;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> arr={{0,1,0},
                             {0,0,0},
                             {0,1,0}};
    cout<<"celebrity is found at index : "<<celebrity(arr);
    return 0;
}