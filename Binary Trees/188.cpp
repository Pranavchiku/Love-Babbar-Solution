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

vector<int> topView(Node *root)
{
    queue<pair<Node*,int>> q; // for bfs
    map<int, int>m; // horizontal height, value
    vector<int> v;
    if(!root) return v;

    q.push({root,0});
    while(!q.empty()){
        Node *t=q.front().first;
        int h=q.front().second;
        q.pop();
        if(m[h]==0) m[h]=t->data; //as we want the value at topmost level so check if already filled, then dont update
        if(t->left) q.push({t->left,h-1});
        if(t->right) q.push({t->right,h+1});
    }
    for(auto x:m){
        v.push_back(x.second);
    }
    return v;
}