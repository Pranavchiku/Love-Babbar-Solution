#include<bits/stdc++.h>
using namespace std;
#define ll long long int

typedef struct Node{
    int data;
    struct Node *left,*right;
}Node;

bool helper(Node *root1,Node *root2){
    if(root2==NULL) return true;
    if(root1==NULL) return false;

    if(root1->data==root2->data){
        if(helper(root1->left,root2->left) && helper(root1->right,root2->right)) return true;
        else return false;
    }
    else return false;
}

bool isSubtree(Node *root1, Node *root2){
    if(root1){
        if(helper(root1,root2)){
            return true;
        }
        return isSubtree(root1->left,root2) || isSubtree(root1->right,root2);
    }
}


