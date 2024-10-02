#include<bits/stdc++.h>
using namespace std;

    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp=arr;
        sort(arr.begin(),arr.end());
        unordered_map<int,int> m;
        int index=0;
        for(int i=0;i<arr.size();i++){
            if(i>0 && arr[i]==arr[i-1]){
                m[arr[i]]=index;
            }
            else{
                index++;
                m[arr[i]]=index;
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=m[temp[i]];
        }
        return arr;
    }

int main(){
    
    return 0;
}