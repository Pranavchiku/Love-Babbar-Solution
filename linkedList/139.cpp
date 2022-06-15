#include <bits/stdc++.h>
using namespace std;
#define ll long long int

typedef struct Node{
    int data;
    struct Node* next;
}NODE;


void linkedlistTraversal(Node *ptr){
    while(ptr!=NULL){
        cout<<ptr->data<<' ';
        ptr=ptr->next;
    }
    cout<<'\n';
}


NODE* insertAtHead(NODE *head, int data){
    NODE* ptr =new(NODE);
    ptr->next=head;
    ptr->data=data;
    return ptr;
}

NODE *insertAtEnd(NODE *head, int data){
    NODE* ptr= new(NODE);
    ptr->data=data;

    NODE* p=head;
    while(p->next!=NULL) p=p->next;

    p->next=ptr;
    ptr->next=NULL;
    return head;
}

//reversing a linked list
NODE *reverseLinkedList(NODE *head){
    NODE *p=head;
    NODE *c=p->next;
    NODE *n=c->next;
    if(c==NULL){
        return head;
    }
    else{
        p->next=NULL;
        while(n!=NULL){
            c->next=p;
            p=c;
            c=n;
            n=n->next;
        }

        c->next=p;
        return c;
    }
}

int main(){
    Node *head = new(Node);

    int n;cin>>n;
    int temp;cin>>temp;
    
    head->data=temp;
    head->next=NULL;
    for(int i=1;i<n;i++){
        cin>>temp;
        head=insertAtEnd(head,temp);
    }

    linkedlistTraversal(head);

    head=reverseLinkedList(head);

    linkedlistTraversal(head);

    return 0;
}