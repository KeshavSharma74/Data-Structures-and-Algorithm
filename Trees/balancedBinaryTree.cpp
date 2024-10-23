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

int dfsHeight(Node* root){
    if(root==NULL){
        return 0;
    }
    int lh=dfsHeight(root->left);
    if(lh==-1){
        return -1;
    }
    int rh=dfsHeight(root->right);
    if(rh==-1){
        return -1;
    }
    if(abs(lh-rh)>1){
        return -1;
    }
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

    root->right->right->left->left=new Node(9);
    root->right->right->left->left->right=new Node(9);
    
    if(dfsHeight(root)==-1){
        cout<<"NOT BALANCED BINARY TREE"<<endl;
    }
    else{
        cout<<"BALANCED BINARY TREE"<<endl;
    }
    return 0;
}

