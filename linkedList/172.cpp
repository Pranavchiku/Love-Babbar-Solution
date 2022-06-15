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
    if(c==NULL){
        return head;
    }
    else{
        Node *n=c->next;
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

Node *compute(Node *head)
{
    Node *p=head;
    Node *temp=head;
    while(p->next!=NULL){
        int flag=0;
        int flag2=0;
        if(p->data<p->next->data){
            if(p==head){
                head=head->next;
                p=p->next;
                flag2=1;
            }
            else{
                Node *q=p;
                temp->next=p->next;
                flag=1;
            }
        }
        if(flag==0)
            temp=p;
        if(flag2==0) p=p->next;
    }   
    return head;
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
    head=compute(head);
    linkedlistTraversal(head);

    return 0;
}