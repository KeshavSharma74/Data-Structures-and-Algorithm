#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int m = n - k;

        int sum = accumulate(cardPoints.begin(),cardPoints.end(),0);
        
        if( m == 0 ) return sum;

        int i = 0,j=0;

        int currSum = 0;
        int maxSum = 0;
        
        while( j < n ){
            
            currSum += cardPoints[j];

            if( j-i+1 >= m){
                maxSum = max(maxSum, sum - currSum);
                currSum -= cardPoints[i];
                i++;
            }

            j++;
        }

        return maxSum;
    }
};