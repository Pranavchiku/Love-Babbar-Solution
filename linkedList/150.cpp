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

int intersectPoint(Node* head1, Node* head2)
{
    Node* p=head1;
    Node* q=head2;
    int c1=0;
    while(p!=NULL){
        c1++;
        p=p->next;
    }
    
    int c2=0;
    while(q!=NULL){
        c2++;
        q=q->next;
    }

    int diff=abs(c1-c2);
    if(c1>c2){
        p=head1;
        q=head2;
        for(int i=0;i<diff;i++) p=p->next;

        while(p!=NULL and q!=NULL and p!=q){
            p=p->next;q=q->next;
        }
        if(p==NULL or q==NULL) return -1;
        return p->data;
    }
    else{
        q=head2;
        p=head1;
        for(int i=0;i<diff;i++) q=q->next;

        while(p!=NULL and q!=NULL and p!=q){
            p=p->next;q=q->next;
        }
        if(p==NULL or q==NULL) return -1;
        return p->data;
    }

}


int main(){

    Node *head1 = new(Node);

    int n;cin>>n;
    int temp;cin>>temp;
    
    head1->data=temp;
    head1->next=NULL;
    for(int i=1;i<n;i++){
        cin>>temp;
        head1=insertAtEnd(head1,temp);
    }


    Node *head2 = new(Node);

    cin>>n;
    cin>>temp;
    
    head2->data=temp;
    head2->next=NULL;
    for(int i=1;i<n;i++){
        cin>>temp;
        head2=insertAtEnd(head2,temp);
    }
    cout<<intersectPoint(head1,head2)<<'\n';
    return 0;
}