#include <bits/stdc++.h>
using namespace std;
#define ll long long int


typedef struct Node{
    int data;
    Node* left;
    Node* right;
    Node *next;
}Node;

Node* createNode(int data){
    Node *n=new(Node);
    n->right=n->left=n->next=NULL;
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

Node *search(Node *root, int key){
    if(root==NULL) return NULL;
    if(key<root->data) return search(root->left,key);
    if(key>root->data) return search(root->right,key);
    if(key==root->data) return root;
}

void inOrder(Node *root){
    if(root!=NULL){
        inOrder(root->left);
        cout<<root->data<<' ';
        inOrder(root->right);
    }
}

Node * inOrderSwap(Node *root){
    if(root->left!=NULL){
        root=root->left;
        while (root->right!=NULL){
            root=root->right;
        }
        return root;
    }
    else{
        root=root->right;
        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }
}

Node *deleteNode(Node *root, int x) {
    if(root==NULL) return NULL;
    if(x==root->data and root->left==NULL and root->right==NULL){
        free(root);
        return NULL;
    }
    if(x<root->data) root->left=deleteNode(root->left,x);
    else if(x>root->data) root->right=deleteNode(root->right,x);
    else{
        Node *iSwap=inOrderSwap(root);
        root->data=iSwap->data;
        if(root->left!=NULL){
            root->left=deleteNode(root->left,iSwap->data);
        }
        else root->right=deleteNode(root->right,iSwap->data);
    }
    return root;
}

Node* inOrderSuccesor(Node *root,int key){
    Node *suc=NULL;
    while(root!=NULL){
        if(key>=root->data) root=root->right;
        else {
            suc=root;
            root=root->left;
        }
    }
    return suc;
}

Node* inOrderPredecessor(Node *root,int key){
    Node *pre=NULL;
    while(root!=NULL){
        if(key<=root->data) root=root->left;
        else{
            pre=root;
            root=root->right;
        }
    }
    return pre;
}

void populateNext2(Node* originalroot, Node *root)
{
    if(root!=NULL){
        populateNext2(originalroot,root->left);
        // cout<<root->data<<'\n';
        // cout<<originalroot->data<<'\n';
        root->next=inOrderSuccesor(originalroot,root->data);
        populateNext2(originalroot,root->right);
    }
}

void populateNext(Node *root)
{
    populateNext2(root,root);
}


void out(Node *root){
    if(root!=NULL){
        out(root->left);
        // cout<<root->data<<'\n';
        if(root->next==NULL) cout<<"ues"<<'\n';
        else cout<<root->next->data<<' ';
        out(root->right);
    }
}

Node *findLCA(Node *root,int n1, int n2, int a){
    if(root->data==a) return root;
    else if (a>root->data) return findLCA(root->right,n1,n2,a);
    else if(a<root->data){
        if(n1==a){
            if(n2<root->data) return findLCA(root->left,n1,n2,a);
            else return root;
        }
        else{
            if(n1<root->data) return findLCA(root->left,n1,n2,a);
            else return root;
        }
    }
}
Node* LCA(Node *root, int n1, int n2)
{
    int a=min(n1,n2);
    return findLCA(root,n1,n2,a);
}