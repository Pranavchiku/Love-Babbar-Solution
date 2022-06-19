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
    return 1+max(height(root->left),height(root->right));
}
void inOrder(Node *root, int &ans){
    if(root!=NULL){
        inOrder(root->left,ans);
        if(root->left!=NULL and root->right!=NULL)
            ans=max(ans,abs(height(root->left)-height(root->right)));
        else if(root->left==NULL and root->right!=NULL)
            ans=max(ans,abs(height(root->right)));
        else if(root->left!=NULL and root->right==NULL)
            ans=max(ans,abs(height(root->left)));
        else ans=max(ans,0);
        inOrder(root->right,ans);
    }
}

bool isBalanced(Node *root)
{
    int ans=INT_MIN;
    inOrder(root,ans);
    if(ans>=2) return 0;
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