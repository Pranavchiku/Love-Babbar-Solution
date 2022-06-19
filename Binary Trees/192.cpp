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

vector<int> diagonal(Node *root)
{
    queue<Node*> q;
    vector<int> v;
    q.push(root);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        while(temp){
            if(temp->left) q.push(temp->left);
            v.push_back(temp->data);
            temp=temp->right;
        }
    }
    return v;
}

int main(){
    int n;cin>>n;
    int temp;cin>>temp;
    Node *root=createNode(temp);
    for(int i=1;i<n;i++){
        cin>>temp;
        insert(root,temp);
    }
    vector<int> v = diagonal(root);
    for(auto &it: v){
        cout<<it<<' ';
    }
    cout<<'\n';
}