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


Node* divide(int N, Node *head){
    if(head==NULL) return NULL;

    Node *p=head;

    if((head->data)%2==0) p=head;
    else p=NULL;
    Node *q=head->next;
    Node *temp=head;

    while(q!=NULL){
        int flag=0;
        // cout<<q->data<<' ';
        // cout<<temp->data<<'\n';

        if((q->data)%2==0){
            // cout<<"here"<<'\n';
            if(p==NULL){
                // cout<<"here2"<<'\n';
                Node *n=new(Node);
                n->data=q->data;
                n->next=head;
                p=n;
                head=p;

                temp->next=q->next;

                // linkedlistTraversal(head);
                flag=1;
            }
            else{
                // cout<<"here3"<<'\n';
                Node *n=new(Node);
                n->data=q->data;
                n->next=p->next;
                p->next=n;
                p=n;

                temp->next=q->next;

                // linkedlistTraversal(head);
                flag=1;
            }

        }

        if(flag==0) temp=q;
        q=q->next;
    }

    // linkedlistTraversal(head);
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
    head=divide(n, head);    

    linkedlistTraversal(head);
    return 0;
}