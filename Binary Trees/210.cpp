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

Node *solve(Node *root, int n1, int n2){
    if(root==NULL or root->data==n1 or root->data==n2) return root;
    
    Node *left=solve(root->left,n1,n2);
    Node *right=solve(root->right,n1,n2);
    
    if(left!=NULL and right!=NULL){
        return root;
    }
    else if(left!=NULL and right==NULL){
        return solve(root->left,n1,n2);
    }
    else if(left==NULL and right!=NULL){
        return solve(root->right,n1,n2);
    }
}
Node* lca(Node* root ,int n1 ,int n2 )
{
    return solve(root,n1,n2);
}

void inOrder(Node *root, int dist, int &ans, int x){
    if(root!=NULL){
        if(root->data==x) {
            ans=dist;
        }
        inOrder(root->left,dist+1,ans,x);
        inOrder(root->right,dist+1,ans,x);
    }
}
int findDist(Node* root, int a, int b) {
    Node *l=lca(root,a,b);
    
    if(l->data==a or l->data==b){
        if(l->data==a){
            int ans=0;
            int dist=1;
            inOrder(l,dist,ans,b);
            return ans-1;
        }
        else{
            int ans=0;
            int dist=1;
            inOrder(l,dist,ans,a);
            return ans-1;
        }
    }
    int ans=0;
    int dist=1;
    int ans2=0;
    inOrder(l,dist,ans,a);
    dist=1;
    inOrder(l,dist,ans2,b);

    return ans2+ans-2;

}

int main(){
    int n;cin>>n;
    int temp;cin>>temp;
    Node *root=createNode(temp);
    for(int i=1;i<n;i++){
        cin>>temp;
        insert(root,temp);
    }
    cout<<findDist(root,10,5)<<'\n';
    return 0;
}