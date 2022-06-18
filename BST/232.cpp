#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct Interval{
    int low, high;
};

typedef struct Node{
    Interval *i;
    int max;
    Node *left, *right;
}Node;

Node *createNode(Interval i){
    Node *n=new Node;
    n->i=new Interval(i);
    n->max=i.high;
    n->left=n->right=NULL;
    return n;
}

Node *insert(Node *root, Interval i){
    if(root==NULL) return createNode(i);
    int l=root->i->low;
    if(i.low<l){
        root->left=insert(root->left,i);
    }
    else{
        root->right=insert(root->right,i);
    }
    if(root->max<i.high) root->max=i.high;

    return root;
}

bool isOverlap(Interval i1, Interval i2){
    if(i1.low<i2.high and i2.low<i1.high) return true;
    return false;
}

Interval *overlapSearch(Node *root, Interval i){
    if(root==NULL) return NULL;

    if(isOverlap(*(root->i),i)) return root->i;

    if(root->left!=NULL and root->left->max>=i.low){
        return overlapSearch(root->left,i);
    }
    return overlapSearch(root->right,i);
}

void printConflicting(Interval arr[], int n){
    Node *root=NULL;
    root=insert(root,arr[0]);

    for(int i=1;i<n;i++){
        Interval *temp=overlapSearch(root,arr[i]);
        if(temp!=NULL){
            cout<<arr[i].low<<','<<arr[i].high<<"conflicts with "<<temp->low<<','<<temp->high<<'\n';
        }
        root=insert(root,arr[i]);
    }
}