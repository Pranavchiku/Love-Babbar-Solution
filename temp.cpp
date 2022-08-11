#include<bits/stdc++.h>
using namespace std;
#define ll long long int

typedef struct Node{
    int data;
    struct Node *next;

    Node (int x){
        data = x;
        next = NULL;
    }
}Node;

Node *solve(Node *head1, Node *head2, int n, int m){
    int diff=abs(n-m);
    if(n>m){
        Node *p=head1;
        Node *q=head2;
        while(diff--){
            p=p->next;
        }
        while(p and q and p->next!=q->next){
            p=p->next;
            q=q->next;
        }
        q=head2;
        while(q!=p->next){
            Node *temp=new Node(q->data);
            temp->next=p->next;
            p->next=temp;
            p=p->next;

            q=q->next;
        }

        p=head1;
        while(p){
            cout<<p->data<<" ";
            p=p->next;
        }
        return head1;
    }

    else{
        Node *p=head1;
        Node *q=head2;
        while(diff--){
            q=q->next;
        }
        while(p and q and p->next!=q->next){
            p=p->next;
            q=q->next;
        }

        p=head1;
        while(p!=q->next){
            Node *temp=new Node(p->data);
            temp->next=q->next;
            q->next=temp;
            q=q->next;
            p=p->next;
        }

        q=head2;
        while(q){
            cout<<q->data<<" ";
            q=q->next;
        }

        return head2;
    }
}

Node *insertAtEnd(Node *end,int x){
    Node *n=new Node(x);
    end->next=n;
    return n;
}
int main(){
    int n,m;cin>>n>>m;
    int commonElements;cin>>commonElements;

    Node *head1=NULL;
    Node *end1=NULL;

    int temp;cin>>temp;
    head1=new Node(temp);
    end1=head1;
    for(int i=1;i<n-commonElements;i++){
        cin>>temp;
        end1=insertAtEnd(end1,temp);
    }
    cin>>temp;
   
    Node *head2=NULL;
    Node *end2=NULL;
    head2=new Node(temp);
    end2=head2;

    for(int i=1;i<m-commonElements;i++){
        cin>>temp;
        end2=insertAtEnd(end2,temp);
    }


    for(int i=0;i<commonElements;i++){
        cin>>temp;
        Node *temp1=new Node(temp);
        end1->next=temp1;
        end1=temp1;
        end2->next=temp1;
        end2=temp1;
    }

    Node *head=solve(head1,head2,n,m);
    return 0;
}

