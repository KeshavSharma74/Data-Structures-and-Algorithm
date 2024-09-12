#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int ans=0;
    for(int i=0;i<heights.size();i++){
        int left=i,right=i; 
        while(left!=0 && heights[i]<=heights[left-1]){
            left--;
        }
        while (right<heights.size()-1 && heights[i]<=heights[right+1])
        {
            right++;
        }
        ans=max(ans,heights[i]*(right-left+1));
    }
    return ans;
}

int main(){
    vector<int> heights={2,1,5,6,2,3};
    cout<<largestRectangleArea(heights)<<endl;
    return 0;
}