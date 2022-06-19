#include <bits/stdc++.h>
using namespace std;
#define ll long long int


typedef struct Node{
    char data;
    Node* left;
    Node* right;
}Node;

Node* createNode(int data){
    Node *n=new(Node);
    n->right=n->left=NULL;
    n->data=data;
    return n;
}

int height(Node *root){
    if(root==NULL) return 0;
    return 1+max(height(root->left),height(root->right));
}
int sumOfLongRootToLeafPath(Node *root)
{
    int ans=0;
    while(root){
        ans+=root->data;
        int left=height(root->left);
        int right=height(root->right);
        if(left==0 and right==0) break;
        else if(left>right){
            root=root->left;
        }
        else if(left<right){
            root=root->right;
        }
        else{
            if(root->left->data<root->right->data){
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
    }
    return ans;

}