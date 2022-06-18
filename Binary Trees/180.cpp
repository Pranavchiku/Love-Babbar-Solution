#include <bits/stdc++.h>
using namespace std;
#define ll long long int

typedef struct Node{
    int data;
    Node *left;
    Node *right;
}Node;

//height of BT
int height(struct Node* node){
    if(node==NULL) return 0;
    return 1+max(height(node->left),height(node->right));
}
