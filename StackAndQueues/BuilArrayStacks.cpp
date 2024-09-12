#include<bits/stdc++.h>
using namespace std;

vector<string> buildArray(vector<int>& target, int n) {
    vector<string> ans;
    int index=0;
    for(int i=1;i<=n && index<target.size();i++){
        ans.push_back("Push");
        if(i!=target[index]){
            ans.push_back("Pop");
        }
        else{
            index++;
        }
    }
    return ans;    
}

int main(){
    vector<int> target={1,3};
    int n=3;
    vector<string> ans=buildArray(target,n);
    for(auto element : ans){
        cout<<element<<"  ";
    }
    return 0;
}