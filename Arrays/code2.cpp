#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n=pref.size();
        int curr=pref[0];
        vector<int> ans(n,curr);
        for(int i=1;i<n;i++){
            ans[i]=curr^pref[i];
            curr=pref[i];
        }
        return ans;
    }
};

int main(){
    
}