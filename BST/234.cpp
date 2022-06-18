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
void inOrder(Node *root, int left, int right, int &flag){
    if(root!=NULL){
        inOrder(root->left,left,root->data-1,flag);
        // cout<<root->data<<' '<<left<<' '<<right<<'\n';
        if(right==1 and root->data==1) flag=1;
        else if(left==right) flag=1;
        inOrder(root->right,root->data+1,right,flag);
    }
}
bool isDeadEnd(Node *root)
{
    int flag=0;
    inOrder(root,INT_MIN,INT_MAX,flag);
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
    cout<<isDeadEnd(root)<<'\n';
    return 0;
}