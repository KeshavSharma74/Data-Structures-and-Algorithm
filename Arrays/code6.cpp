#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int NumberOfOnes(int n){
        int cnt=0;
        while(n){
            if(n&1) cnt++;
            n=n>>1;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            ans.push_back(NumberOfOnes(i));
        }
        return ans;
    }
};

int main(){
    
    return 0;
}