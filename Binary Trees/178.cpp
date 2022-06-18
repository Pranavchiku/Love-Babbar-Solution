#include <bits/stdc++.h>
using namespace std;
#define ll long long int

typedef struct Node{
    int data;
    Node *left;
    Node *right;
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

void bfs(Node *root, queue<Node*> &q, vector<int> &v){
    if(root==NULL) return;
    else{
        if(q.empty()) return;
        Node *temp=q.front();
        q.pop();
        if(temp->left!=NULL and temp->right!=NULL){
            q.push(temp->left);
            q.push(temp->right);
            v.push_back(temp->left->data);
            v.push_back(temp->right->data);
            bfs(root,q,v);
        }
        else{
            if(temp->left!=NULL and temp->right==NULL){
                q.push(temp->left);
                v.push_back(temp->left->data);
                bfs(root,q,v);
            }
            else if(temp->left==NULL and temp->right!=NULL){
                q.push(temp->right);
                v.push_back(temp->right->data);
                bfs(root,q,v);
            }
            else{
                bfs(root,q,v);
            }
        }   
    }
}

vector<int> levelOrder(Node* node)
{
    vector<int> v;
    queue<Node*> q;
    v.push_back(node->data);
    q.push(node);
    bfs(node, q,v);
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
    vector<int> v = levelOrder(root);
    for(auto& it: v) cout<<it<<' ';
    cout<<'\n';
    return 0;
}