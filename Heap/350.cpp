#include <bits/stdc++.h>
using namespace std;
#define ll long long int

typedef struct Node{
    int data;
    Node *left;
    Node* right;
}Node;

bool isHeap(Node* root) {
    queue<Node*> q;
    q.push(root);
    vector<Node*> v;
    while(!q.empty()){
        Node *curr=q.front();
        q.pop();
        v.push_back(curr);
        if(curr==NULL){
            while(!q.empty() and q.front()==NULL){
                q.pop();
            }
            if(!q.empty()) return false;
            else return true;
        }
        else{
            if(curr->left!=NULL and curr->right!=NULL){
                if(curr->data<curr->left->data or curr->data<curr->right->data) return false;
            }
            else if(curr->left!=NULL and curr->right==NULL){
                if(curr->data<curr->left->data) return false;
            }
            else if(curr->right!=NULL and curr->left==NULL){
                if(curr->data<curr->right->data) return false;
            }
        }
        q.push(curr->left);
        q.push(curr->right);
    }
    return true;
}