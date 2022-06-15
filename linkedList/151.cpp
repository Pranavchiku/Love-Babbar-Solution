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

Node* mergeTwoLists(Node *start,Node *mid)
{
    if(start==NULL)
        return mid;
    if(mid==NULL)
        return start;
    Node *head = NULL,*tail = NULL;
    if(start->data <= mid->data)
    {
        head = start;
        tail = start;
        start = start->next;
    }
    else
    {
        head = mid;
        tail = mid;
        mid = mid->next;
    }
    while(start!=NULL && mid!=NULL)
    {
        if(start->data <= mid->data)
        {
            tail->next = start;
            start = start->next;
            tail = tail->next;
        }
        else
        {
            tail->next = mid;
            mid = mid->next;
            tail = tail->next;
        }
    }
    if(start!=NULL)
        tail->next = start;
    if(mid!=NULL)
        tail->next = mid;
    return head;
}
   
Node* mergeSort(Node* head) {
    // your code here
    if(head==NULL || head->next==NULL)
        return head;
    Node *slow = head,*fast = head,*temp = NULL;
    while(fast!=NULL && fast->next!=NULL)
    {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    temp->next = NULL;
    Node *start = mergeSort(head);
    Node *mid = mergeSort(slow);
    return mergeTwoLists(start,mid);
}


int main(){
    return 0;
}