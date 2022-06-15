#include <bits/stdc++.h>
using namespace std;
#define ll long long int

typedef struct Node{
    int data;
    struct Node* next;
}Node;


void linkedlistTraversal(Node *ptr){
    while(ptr!=NULL){
        cout<<ptr->data<<' ';
        ptr=ptr->next;
    }
    cout<<'\n';
}


Node* insertAtHead(Node *head, int data){
    Node* ptr =new(Node);
    ptr->next=head;
    ptr->data=data;
    return ptr;
}

Node *insertAtEnd(Node *head, int data){
    Node* ptr= new(Node);
    ptr->data=data;

    Node* p=head;
    while(p->next!=NULL) p=p->next;

    p->next=ptr;
    ptr->next=NULL;
    return head;
}

Node *reverseLinkedList(Node *head){
    Node *p=head;
    Node *c=p->next;
    Node *n=c->next;
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

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *s=head;
    Node *f=head->next;
    while(f!=head and f->next!=head){
        s=s->next;
        f=f->next->next;
    }

    *head1_ref=head;
    *head2_ref=s->next;

    s->next=*head1_ref;

    Node* cur=*head2_ref;
    while(cur->next!=head) cur=cur->next;
    cur->next=*head2_ref;
    
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

    Node* p=head;
    while(p->next!=NULL) p=p->next;
    p->next=head;


    splitList(head,NULL,NULL);

    return 0;
}

