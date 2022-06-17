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

Node* insertRec(Node *root, int key){
    if(root==NULL) return root= createNode(key);
    if(key<root->data){
        root->left=insertRec(root->left,key);

    }
    else root->right=insertRec(root->right,key);
    return root;
}

int constructBST(vector<int> &preorder, int n, int pos, Node *curr, int left, int right){
    if(pos==n or preorder[pos]<left or preorder[pos]>right) return pos;

    if(preorder[pos]<curr->data){
        curr->left=createNode(preorder[pos]);
        pos+=1;
        pos=constructBST(preorder,n,pos,curr->left,left,curr->data-1);
    }

    if(pos==n or preorder[pos]<left or preorder[pos]>right) return pos;

    curr->right = createNode(preorder[pos]);
    pos+=1;
    pos=constructBST(preorder,n,pos,curr->right,curr->data+1,right);
    return pos;
}

Node* bstFromPreOrder(vector<int> &preorder){
    int n=preorder.size();
    if(n==0) return NULL;

    Node *root=createNode(preorder[0]);
    if(n==1) return root;

    constructBST(preorder,n,1,root,INT_MIN,INT_MAX);
    return root;
}
int main(){
    int n;cin>>n;
    int temp;cin>>temp;
    Node *root=insertRec(root,temp);
    for(int i=1;i<n;i++){
        cin>>temp;
        insertRec(root,temp);
    }

    return 0;
}