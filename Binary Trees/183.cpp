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

void inOrderIterative(Node *root){
    stack<Node*>s;
    vector<int> v;
    while(!s.empty() or root!=NULL){
        if(root!=NULL){
            s.push(root);
            root=root->left;
        }
        else{
            root=s.top();
            s.pop();
            v.push_back(root->data);

            root=root->right;
        }
    }
    for(auto& it: v) cout<<it<<' ';
    cout<<'\n';
}

void preOrderIterative(Node *root){
    stack<Node*> s;
    vector<int> v;
    s.push(root);
    while(!s.empty()){
        Node *temp=s.top();
        s.pop();
        v.push_back(temp->data);
        if(temp->right){
            s.push(temp->right);
        }
        if(temp->left){
            s.push(temp->left);
        }
    }
    for(auto& it: v) cout<<it<<' ';
    cout<<'\n';
}

void postOrderIterative(Node *root){
    stack<Node*> s;
    s.push(root);
    stack<int> out;
    while(!s.empty()){
        Node *temp=s.top();
        s.pop();
        out.push(temp->data);
        if(temp->left){
            s.push(temp->left);
        }
        if(temp->right){
            s.push(temp->right);
        }
    }
    while(!out.empty()){
        cout<<out.top()<<' ';
        out.pop();
    }
}

int main(){
    int n;cin>>n;
    int temp;cin>>temp;
    Node *root=createNode(temp);
    for(int i=1;i<n;i++){
        cin>>temp;
        insert(root,temp);
    }
    postOrderIterative(root);
    return 0;
}