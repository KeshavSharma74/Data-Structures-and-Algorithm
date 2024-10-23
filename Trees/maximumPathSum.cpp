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

int maxPathSum(Node* root,int &maxi){
    if(root==NULL){
        return 0;
    }
    int lh=max(0,maxPathSum(root->left,maxi));
    int rh=max(0,maxPathSum(root->right,maxi));
    maxi=max(maxi,root->data+lh+rh);
    return root->data+lh+rh;
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
    int maxi=0;
    maxPathSum(root,maxi);
    cout<<maxi;
    return 0;
}

