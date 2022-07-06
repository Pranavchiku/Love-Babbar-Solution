#include<bits/stdc++.h>
using namespace std;
#define ll long long int

typedef struct node{
    int data;
    struct node* next;
}Node;

//naive approach for recursion
Node* reverseLinkedList(Node *head, Node *prev){
    if(head==NULL) return prev;
    Node *curr=head;
    Node *next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
    return reverseLinkedList(next,prev);
}

//new approach where
//you keep put the previous node in the next node
Node* reverseLinkedListRecursive(Node *head){
    if(head==NULL or head->next==NULL) return head;
    Node *newHead=reverseLinkedListRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;
}

Node *insertAtEnd(Node *end, int key){
    Node *ptr=new(Node);
    ptr->data=key;
    ptr->next=NULL;
    end->next=ptr;
    return ptr;
}

int main(){
    //linked list creation
    Node* head=new Node;
    head->data=1;
    head->next=NULL;
    Node* end=head;
    for(int i=2;i<=5;i++){
        end=insertAtEnd(end,i);
    }
    head=reverseLinkedListRecursive(head);
    Node* p=head;
    while(p!=NULL){
        cout<<p->data<<' ';
        p=p->next;
    }
    return 0;
}