#include <bits/stdc++.h>
using namespace std;
#define ll long long int

typedef struct Node{
    char data;
    int freq;
    struct Node* next;
}Node;


void linkedlistTraversal(Node *ptr){
    while(ptr!=NULL){
        cout<<ptr->data<<' ';
        ptr=ptr->next;
    }
    cout<<'\n';
}


Node* insertAtHead(Node *head, char data){
    Node* ptr =new(Node);
    ptr->next=head;
    ptr->data=data;
    ptr->freq=1;
    return ptr;
}

Node *insertAtEnd(Node *head, char data){
    Node* ptr= new(Node);
    ptr->data=data;

    Node* p=head;
    while(p->next!=NULL) p=p->next;

    p->next=ptr;
    ptr->next=NULL;
    ptr->freq=1;
    return head;
}

Node* insert(Node *head, char data){

    Node *p=head;
    while(p and p->data!=data) p=p->next;
    if(p==NULL){
        head=insertAtEnd(head,data);
        return head;
    }
    else{
        p->freq++;
        return head;
    }
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


string FirstNonRepeating(string a){
    Node *head=new(Node);
    head->data=a[0];
    head->freq=1;
    head->next=NULL;
    string out="";
    out+=a[0];
    int n=a.length();
    for(int i=1;i<n;i++){
        head=insert(head,a[i]);
        Node  *p=head;
        while(p and p->freq!=1) p=p->next;
        if(p==NULL) out+='#';
        else out+=p->data;
    }

    return out;
}
int main(){
   string s= FirstNonRepeating("aabc");
}

