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

Node* removeDuplicates(struct Node* head)
{
    Node *p=head;
    Node *q=head->next;
    while(q!=NULL){

        if(p->data==q->data){
            p->next=q->next;
            q=p->next;
        }
        else{
            p=p->next;
            q=p->next;
        }
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
    removeDuplicates(head);
}