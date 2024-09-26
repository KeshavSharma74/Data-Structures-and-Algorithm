#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> arr,int target){
    unordered_map<int,int> m;
    for (int i = 0; i < arr.size(); i++)
    {
        int moreNeeded=target-arr[i];
        if(m.find(moreNeeded)!=m.end()){
            return {i,m[moreNeeded]};
        }
        m[arr[i]]=i;
    }
    return {-1,-1};
}

// this can also be done using map

bool isPresent(vector<int> arr,int target){
    sort(arr.begin(),arr.end());
    int left=0,right=arr.size()-1;
    while(left<right){
        int sum=arr[left]+arr[right];
        if(sum==target){
            return true;
        }
        else if(sum<target){
            left++;
        }
        else{
            right--;
        }
    }
    return false;
}

int main(){
    vector<int> arr={1,3,4,3,5,3,5};
    int target=10;
    cout<<isPresent(arr,10);
    return 0;
}