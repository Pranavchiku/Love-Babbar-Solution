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


vector <int> zigZagTraversal(Node* root)
{
    queue<Node*> q;
    vector<int> v;
    q.push(root);
    int f=1;
    while(!q.empty()){
        vector<int> temp;
        int s=q.size();
        while(s--){
            Node *t=q.front();
            temp.push_back(t->data);
            q.pop();
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        if(f%2==0) reverse(temp.begin(),temp.end());
        for(auto& it: temp){
            v.push_back(it);
        }
        f=!f;
    }
    return v;

}