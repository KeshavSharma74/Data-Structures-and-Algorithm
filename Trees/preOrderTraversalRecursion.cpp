#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};

void preOrderTraversal(Node* root,vector<int> &ans){
    if(root==NULL){
        return ;
    }
    ans.push_back(root->data);
    preOrderTraversal(root->left,ans);
    preOrderTraversal(root->right,ans);
}

void printAnswer(vector<int> ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->left=new Node(6);
    root->left->right->right=new Node(7);
    root->right=new Node(3);
    root->right->right=new Node(8);
    root->right->right->left=new Node(9);
    vector<int> ans;
    preOrderTraversal(root,ans);
    printAnswer(ans);
    return 0;
}