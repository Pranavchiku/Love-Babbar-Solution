#include <bits/stdc++.h>
using namespace std;
#define ll long long int

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* bottom;
}Node;

Node* merge(Node *a, Node*b){
   if(a==NULL)
       return b;
   if(b==NULL)
       return a;
   Node* result=NULL;
   if(a->data < b->data){
       result=a;
       result->bottom=merge(a->bottom, b);
   }
   else{
       result=b;
       result->bottom=merge(b->bottom, a);
   }
   result->next=NULL;
   return result;
}
Node *flatten(Node *root){
  // Your code here
  if(root==NULL || root->next==NULL) return root;
  root->next=flatten(root->next);
  root=merge(root, root->next);
  return root;
}

int main(){
    Node *root=new(Node);
    Node *b1=new(Node);
    Node *b2=new(Node);
    Node *b3=new(Node);

    Node *n1=new(Node);
    Node *nb1=new(Node);


    root->data=5;
    root->next=n1;
    root->bottom=b1;

    b1->data=7;
    b1->bottom=b2;

    b2->bottom-b3;
    b2->data=8;

    b3->bottom=NULL;
    b3->data=30;


    n1->next=NULL;
    n1->bottom=nb1;
    n1->data=10;

    nb1->bottom=NULL;
    nb1->data=20;

    root=flatten(root);


    Node *p=root;
    while(p){
        cout<<p->data<<' ';
        p=p->bottom;
    }
    cout<<'\n';

    return 0;
}