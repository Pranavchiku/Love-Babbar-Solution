#include <bits/stdc++.h>
using namespace std;
#define ll long long int


typedef struct Node{
    int data;
    Node* left;
    Node* right;
}Node;

Node* createNode(int data){
    Node *n=new(Node);
    n->right=n->left=NULL;
    n->data=data;
    return n;
}

void insert(Node *root, int key){

    Node* prev=NULL;
    Node *n=createNode(key);
    while(root!=NULL){
        prev=root;
        if(key==root->data) return;
        else if(key<root->data) root=root->left;
        else root=root->right;
    }
    if(key>prev->data) prev->right=n;
    else prev->left=n;
    

}

int height(Node *root){
    if(root==NULL) return 0;
    if(root->left==NULL and root->right==NULL) return 1;
    if (root->left==NULL and root->right!=NULL){
        return 1+root->right->data;
    }
    if(root->left!=NULL and root->right==NULL){
        return 1+root->left->data;
    }
    if (root->left!=NULL and root->right!=NULL){
        return max(root->left->data,root->right->data)+1;
    }
}
void inOrder(Node *root, int &ans){
    if(root!=NULL){
        inOrder(root->left,ans);
        inOrder(root->right,ans);
        // cout<<root->data<<' ';
        root->data=height(root);
        // cout<<root->data<<'\n';
        ans=max(ans,root->data);
    }
}
void solve(Node *root, int &ans){
    if(root!=NULL){
        solve(root->left,ans);
        if(root->left!=NULL and root->right!=NULL){
            ans=max(ans,1+root->left->data+root->right->data);
        }
        else if(root->left==NULL and root->right!=NULL){
            ans=max(ans,root->right->data+1);
        }
        else if(root->left!=NULL and root->right==NULL){
            ans=max(ans,root->left->data+1);
        }
        else{
            ans=max(ans,root->data);
        }
        solve(root->right,ans);
    }
}
int diameter(Node* root) {
    int ans=0;
    inOrder(root,ans);
    ans=0;
    solve(root,ans);
    return ans;
}
int main(){
    int n;cin>>n;
    int temp;cin>>temp;
    Node *root=createNode(temp);
    for(int i=1;i<n;i++){
        cin>>temp;
        insert(root,temp);
    }
    cout<<diameter(root)<<'\n';

    return 0;
}