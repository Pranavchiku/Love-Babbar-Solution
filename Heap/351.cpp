#include <bits/stdc++.h>
using namespace std;
#define ll long long int

typedef struct Node{
    int data;
    Node *left;
    Node* right;
}Node;

void inOrder(Node *root, vector<int> &arr){
    if(root){
        inOrder(root->left,arr);
        arr.push_back(root->data);
        inOrder(root->right,arr);
    }
}

void bstToMinHeap(Node *root, vector<int> &arr, int *i){
    if(root==NULL) return;

    root->data=arr[++*i];
    bstToMinHeap(root->left,arr,i);
    bstToMinHeap(root->right,arr,i);
}

void convertBSTtoMinHeap(Node *root){
    vector<int> arr;
    int i=-1;

    inOrder(root,arr);
    bstToMinHeap(root,arr,&i);
}