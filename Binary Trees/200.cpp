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

void inOrder(Node *root, int level, int &curr,int &flag){
    if(root==NULL or flag==0) return; //base case
    //case for judgment
    if(root->left==NULL and root->right==NULL){
        if(curr==-1){
            curr=level;
        }
        if(curr!=-1 and curr!=level) flag=0;
    }
    else{
        //traversing
        inOrder(root->left,level+1,curr,flag);
        inOrder(root->right,level+1,curr,flag);
    }
}

bool check(Node *root)
{
    int flag=1;
    int level=0;
    int curr=-1;
    inOrder(root,level,curr,flag);
    return flag;
}

int main(){
    int n;cin>>n;
    int temp;cin>>temp;
    Node *root=createNode(temp);
    for(int i=1;i<n;i++){
        cin>>temp;
        insert(root,temp);
    }
    cout<<check(root)<<'\n';
    return 0;
}