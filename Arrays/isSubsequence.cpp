#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sPoint=0;
        int tPoint=0;
        while(sPoint<s.length() && tPoint<t.length()){
            if(s[sPoint]==t[tPoint]){
                sPoint++;
            }
            tPoint++;
        }
        return sPoint==s.size();
    }
};

int main(){
    
    return 0;
}