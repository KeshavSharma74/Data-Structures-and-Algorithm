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

void postOrderTraversalIterativeUsingTwoStacks(Node* root,vector<int> &ans){
    if(root==NULL){
        return;
    }
    stack<Node*> st1;
    stack<Node*> st2;
    st1.push(root);
    while(!st1.empty()){
        Node* node=st1.top();
        st1.pop();
        st2.push(node);
        if(node->left!=NULL){
            st1.push(node->left);
        }
        if(node->right!=NULL){
            st1.push(node->right);
        }
    }
    while (!st2.empty()){
        Node* node=st2.top();
        st2.pop();
        ans.push_back(node->data);
    }
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
    postOrderTraversalIterativeUsingTwoStacks(root,ans);
    printAnswer(ans);
    return 0;
}