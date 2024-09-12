#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &nums, int n)
{
    // vector<int> ans;
    // for(int i=0;i<nums.size();i++){
    //     int mini=-1;
    //     int element=nums[i];
    //     for(int j=i+1;j<nums.size();j++){
    //         if(element>nums[j]){
    //             mini=nums[j];
    //             break;
    //         }
    //     }
    //     ans.push_back(mini);
    // }
    // return ans;
    
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    for(int i=n-1;i>=0;i--){
        int element=nums[i];
        while(st.top()>=element){
            st.pop();
        }
        ans[i]=st.top();
        st.push(element);
    }
    
    return ans;
}

int main(){
    vector<int> nums={2,1,4,3};
    vector<int> ans;
    // brute force solution
    for(int i=0;i<nums.size();i++){
        int mini=-1;
        int element=nums[i];
        for(int j=i+1;j<nums.size();j++){
            if(element>nums[j]){
                mini=nums[j];
                break;
            }
        }
        ans.push_back(mini);
    }
    for(auto element : ans) cout<<element<<" ";
    return 0;
}