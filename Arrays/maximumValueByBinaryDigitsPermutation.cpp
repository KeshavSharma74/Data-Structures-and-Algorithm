#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string binary(int n){
        string str="";
        while(n){
            if(n&1)     str+='1';
            else    str+='0';
            n=n>>1;
        }
        reverse(str.begin(),str.end());
        return str;
    }

    long long decimal(string str){
      long long ans=0;
      int index=str.size()-1;
      int i=0;
      while(index>=0){
        if(str[index]=='1') ans+=pow(2,i);
        i++;
        index--;
      }
      return ans;
    }

    int actualNumber(int n1,int n2,int n3){
      return decimal(binary(n1)+binary(n2)+binary(n3));
    }

    int maxGoodNumber(vector<int>& arr) {
        int maxi=INT_MIN;
        int n1=arr[0];
        int n2=arr[1];
        int n3=arr[2];
        maxi=max(maxi,actualNumber(n1,n2,n3));
        maxi=max(maxi,actualNumber(n1,n3,n2));
        maxi=max(maxi,actualNumber(n2,n3,n1));
        maxi=max(maxi,actualNumber(n2,n1,n3));
        maxi=max(maxi,actualNumber(n3,n1,n2));
        maxi=max(maxi,actualNumber(n3,n2,n1)); 
        return maxi;
    }
};

int main(){
    
    return 0;
}