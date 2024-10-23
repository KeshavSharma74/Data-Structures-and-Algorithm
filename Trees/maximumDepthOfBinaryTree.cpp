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

int maxDepth(Node* root){
    if(root==NULL){
        return 0;
    }
    int lh=maxDepth(root->left);
    int rh=maxDepth(root->right);
    return 1+max(lh,rh);
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
    cout<<maxDepth(root)<<endl;
    return 0;
}

