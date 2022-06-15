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

Node* removeLoop(Node* head)
{
    Node *f=head;
    Node *s=head;

    while(s!=NULL and f!=NULL and f->next!=NULL){
        s=s->next;
        f=f->next->next;
        if(s==f){
            break;
        }
    }

    if(s!=f) return NULL;

    if(s==head){
        // while(f->next!=s) f=f->next;
        // f->next=NULL;
        // return;
        return head;
    }
    else{
        s=head;
        while(s->next!=f->next){
            s=s->next;f=f->next;
        }
        // f->next=NULL;
        return f->next;
    }
}

int main(){

}