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

void preOrderTraversalIterative(Node* root,vector<int> &ans){
    if(root==NULL){
        return;
    }
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* node=st.top();
        st.pop();
        ans.push_back(node->data);
        if(node->right!=NULL)
            st.push(node->right);
        if(node->left!=NULL)   
            st.push(node->left);
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
    preOrderTraversalIterative(root,ans);
    printAnswer(ans);
    return 0;
}