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

void inOrderTraversalIterative(Node* root,vector<int> &ans){
    if(root==NULL){
        return;
    }
    stack<Node*> st;
    Node* curr=root;
    while(true){
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        else{
            if(st.empty())  break;
            curr=st.top();
            st.pop();
            ans.push_back(curr->data);
            curr=curr->right;
        }
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
    inOrderTraversalIterative(root,ans);
    printAnswer(ans);
    return 0;
}