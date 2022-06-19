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


void leftBoundry(Node* root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            return;
        }
        ans.push_back(root->data);
        if(root->left){
            leftBoundry(root->left, ans);
        }
        else{
            leftBoundry(root->right, ans);
        }
    }
    
    void leafNodes(Node* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        leafNodes(root->left, ans);
        leafNodes(root->right, ans);
    }
    
    void rightBoundry(Node* root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            return;
        }
        if(root->right){
            rightBoundry(root->right, ans);
        }
        else{
            rightBoundry(root->left, ans);
        }
        ans.push_back(root->data);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        ans.push_back(root->data);
        
        leftBoundry(root->left, ans);
        
        leafNodes(root->left, ans);
        leafNodes(root->right, ans);
        
        rightBoundry(root->right, ans);
        
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


}