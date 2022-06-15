#include <bits/stdc++.h>
using namespace std;
#define ll long long int

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;


void linkedlistTraversal(Node *head){
    Node *ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<' ';
        ptr=ptr->next;
    }
    cout<<'\n';
}

Node* insertAtEnd(Node* head,int data){
    Node *p=head;
    while(p->next!=NULL) p=p->next;
    Node *ptr=new(Node);

    ptr->next=NULL;
    ptr->prev=p;
    ptr->data=data;
    p->next=ptr;
    return head;
}

Node* reverseDLL(Node * head)
{
    Node *p=head;
    Node *c=p->next;

    if(c==NULL) return head;
    else{
        Node *n=c->next;
        p->next=NULL;
        p->prev=c;
        while(n!=NULL){
            c->next=p;
            c->prev=n;
            p=c;
            c=n;
            n=n->next;
        }
        c->next=p;
        c->prev=n;
        return c;
    }
}

int main(){
    Node *head = new(Node);

    int n;cin>>n;
    int temp;cin>>temp;
    
    head->data=temp;
    head->next=NULL;
    head->prev=NULL;
    for(int i=1;i<n;i++){
        cin>>temp;
        head=insertAtEnd(head,temp);
    }

    linkedlistTraversal(head);

    head=reverseDLL(head);

    linkedlistTraversal(head);
    return 0;
}