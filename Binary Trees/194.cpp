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

int findIndex(string str, int si, int ei){
    if(si>ei) return -1;

    stack<char> s;
    for(int i=si;i<=ei;i++){
        if(str[i]=='(') s.push(str[i]);

        else if(str[i]==')'){
            if(s.top()=='('){
                s.pop();

                if(s.empty()) return i;
            }
        }
    }

    return -1;
}

Node *treeFromString(string str, int si, int ei){
    if(si>ei) return NULL;

    Node *root=createNode(str[si]-'0');
    int index=-1;

    if(si+1<=ei and str[si+1]=='('){
        index=findIndex(str,si+1,ei);
    }
    if(index!=-1){
        root->left=treeFromString(str,si+2,index-1);
        root->right=treeFromString(str,index+2,ei-1);
    }
    return root;
}