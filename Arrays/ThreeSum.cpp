#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &arr,int target){
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i=0;i<arr.size();i++){
        if(i>0 && arr[i]==arr[i-1]){
            continue;
        }
        int j=i+1,k=arr.size()-1;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];
            if(sum==target){
                vector<int> v={arr[i],arr[j],arr[k]};
                ans.push_back(v);
                j++;
                k--;
                while(j<k && arr[j]==arr[j-1])  j++;
                while(j<k && arr[k]==arr[k+1])  k--;
            }
            else if(sum>target){
                k--;
            }
            else if(sum<target){
                j++;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr={-1,0,1,2,-1,-4};
    vector<vector<int>> ans=threeSum(arr,0);
    for(auto v : ans){
        for(auto element : v){
            cout<<element<<"  ";
        }
        cout<<endl;
    }
    return 0;
}