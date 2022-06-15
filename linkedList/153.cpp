#include <bits/stdc++.h>
using namespace std;
#define ll long long int

typedef struct ListNode{
    int data;
    struct ListNode* next;
}ListNode;


void linkedlistTraversal(ListNode *ptr){
    while(ptr!=NULL){
        cout<<ptr->data<<' ';
        ptr=ptr->next;
    }
    cout<<'\n';
}


ListNode* insertAtHead(ListNode *head, int data){
    ListNode* ptr =new(ListNode);
    ptr->next=head;
    ptr->data=data;
    return ptr;
}

ListNode *insertAtEnd(ListNode *head, int data){
    ListNode* ptr= new(ListNode);
    ptr->data=data;

    ListNode* p=head;
    while(p->next!=NULL) p=p->next;

    p->next=ptr;
    ptr->next=NULL;
    return head;
}

ListNode *reverseLinkedList(ListNode *head){
    ListNode *p=head;
    ListNode *c=p->next;
    ListNode *n=c->next;
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

ListNode* middleNode(ListNode* head) {
    ListNode *s=head;
    ListNode *f=head;

    while(f!=NULL and f->next!=NULL){
        f=f->next->next;
        s=s->next;
    }

    return s;
}
int main(){
    return 0;
}