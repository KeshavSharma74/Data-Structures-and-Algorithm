#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int minDiff=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();i++){
            int left=i+1,right=nums.size()-1;
            while(left<right){
                int currSum=nums[left]+nums[right]+nums[i];
                if(currSum==target){
                    return currSum;
                }
                else if(currSum<target){
                    left++;
                }
                else{
                    right--;
                }
                if(abs(currSum-target)<abs(minDiff-target)){
                    minDiff=currSum;
                }
            }
        }
        return minDiff;
    }
};

int main(){
    
    return 0;
}