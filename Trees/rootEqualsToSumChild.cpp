#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public: 
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int data){
            this->val=data;
            this->left=NULL;
            this->right=NULL;
        }
};

class Solution {
public:
    bool checkTree(TreeNode* root) {
        return (root->val)==(root->left->val+root->right->val);
    }
};

int main(){
    
    return 0;
}