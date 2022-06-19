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

void height(Node *root){
    if(root==NULL) return;
    else if(root->left!=NULL and root->right!=NULL){
        root->data=1+max(root->left->data,root->right->data);
    }
    else if(root->left!=NULL and root->right==NULL){
        root->data=1+root->left->data;
    }
    else if(root->left==NULL and root->right!=NULL){
        root->data=1+root->right->data;
    }
    else if(root->left==NULL and root->right==NULL){
        root->data=1;
    }
}
void inOrder(Node *root, int &ans){
    if(root!=NULL){
        inOrder(root->left,ans);
        if(root->left!=NULL and root->right!=NULL)
            ans=max(ans,abs(root->left->data-root->right->data));
        else if(root->left==NULL and root->right!=NULL)
            ans=max(ans,abs(root->right->data));
        else if(root->left!=NULL and root->right==NULL)
            ans=max(ans,abs(root->left->data));
        else ans=max(ans,0);
        inOrder(root->right,ans);
    }
}
void traversal(Node *root){
    if(root!=NULL){
        traversal(root->left);
        cout<<root->data<<' ';
        traversal(root->right);
    }
}
bool isBalanced(Node *root)
{
    int ans=INT_MIN;
    traversal(root);cout<<'\n';
    inOrder(root,ans);
    if(ans>2) return 0;
    else return 1;
}


int main(){
    int n;cin>>n;
    int temp;cin>>temp;
    Node *root=createNode(temp);
    for(int i=1;i<n;i++){
        cin>>temp;
        insert(root,temp);
    }
    cout<<isBalanced(root)<<'\n';
}