#include<bits/stdc++.h>
using namespace std;

bool checkCelebrity(int i,vector<vector<int>> &mat,int n){
    // row should have all 0
    for(int j=0;j<n;j++){
        if(mat[i][j]==1 && i!=j){
            return false;
        }
    }
    // column should have all 1 except i==j
    for(int j=0;j<n;j++){
        if(mat[j][i]==0 && i!=j){
            return false;
        }
    }
    return true;
}

int celebrity(vector<vector<int>> &mat){
    int n=mat.size();
    for(int i=0;i<n;i++){
        if(checkCelebrity(i,mat,n)){
            return i;
        }
    }
    return -1;
} 

int main(){
    vector<vector<int>> arr={{0,1,0},
                             {0,0,0},
                             {0,1,0}};
    cout<<"celebrity is found at index : "<<celebrity(arr);
    return 0;
}