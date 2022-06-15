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

bool isPalindrome(Node *head)
{
    Node *s=head;
    Node *f=head->next;

    Node *temp=NULL;

    if(f==NULL) return true;
    else{
        while(f!=NULL and f->next!=NULL){
            temp=s;
            s=s->next;
            f=f->next->next;
        }

        Node *head1=s->next;
        s->next=NULL;
        head1=reverseLinkedList(head1);

        Node *p=head;
        Node *q=head1;

        while(p and q and p->data==q->data){
            p=p->next;q=q->next;
        }

        if(p==NULL or q==NULL) return true;
        else return false;
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

    cout<<isPalindrome(head)<<'\n';
    return 0;
}