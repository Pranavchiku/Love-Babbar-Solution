#include <bits/stdc++.h>
using namespace std;
#define ll long long int


typedef struct node{
    int data;
    struct node* next;
}node;



void linkedlistTraversal(node *ptr){
    while(ptr!=NULL){
        cout<<ptr->data<<' ';
        ptr=ptr->next;
    }
    cout<<'\n';
}


node* insertAtHead(node *head, int data){
    node* ptr =new(node);
    ptr->next=head;
    ptr->data=data;
    return ptr;
}

node *insertAtEnd(node *head, int data){
    node* ptr= new(node);
    ptr->data=data;

    node* p=head;
    while(p->next!=NULL) p=p->next;

    p->next=ptr;
    ptr->next=NULL;
    return head;
}


struct node *reverse2 (struct node *head, int k)
{ 
    if(!head) return NULL;
    node *c=head;
    node *n=NULL;
    node *p=NULL;
    int count=0;
    while(c!=NULL and count<k){
        n=c->next;
        c->next=p;
        p=c;
        c=n;
        count++;
    }

    if(n!=NULL){
        head->next=reverse2(n,k);
    }
    
    return p;
    
}

int main(){
    return 0;
}