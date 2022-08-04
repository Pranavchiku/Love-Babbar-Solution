#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
  int data;
  Node *next;
  
}Node;

Node *insert(Node* end, int val){
  Node *n= new Node;
  n->data=val;
  n->next=NULL;
  end->next=n;
  return n;
}

void loopHere(Node *head, Node *tail, int position){
  if(position==0) return;
  Node *walk=head;
  int i=0;
  while(i<position-1){
    walk=walk->next;
    i++;
  }
  // cout<<walk->data<<'\n';
  tail->next=walk;
}

Node *removeLoop(Node *head){
  Node *s=head;
  Node *f=head;
  while(f->next and f->next->next){
    s=s->next;
    f=f->next->next;
    if(s==f){
      break;
    }
  }
  if(f==NULL or f->next==NULL) {

    return head;
  }
  if(s!=f) {

    return head;
  }
  if(s==head){
    while(s and s->next!=head) s=s->next;
    s->next=NULL;
    Node *temp=s;
    Node *end=s;
    s=head;
    while(s!=temp){
      end=insert(end,s->data);
      s=s->next;
    }
    end=insert(end,s->data);
    return head;
  }
  else{
    s=head;
    while(s->next!=f->next) s=s->next,f=f->next;
    f->next=NULL;
    Node *end=f;
    s=s->next;
    while(s!=f){
      end=insert(end,s->data);
      s=s->next;
    }
    end=insert(end,s->data);
    return head;
  }
}

int main(){
  int n;cin>>n;
  Node *head= new Node;
  int temp;cin>>temp;
  head->data=temp;
  head->next=NULL;
  Node *end=head;
  for(int i=1;i<n;i++){
    cin>>temp;
    end=insert(end,temp);
  }

  int position;cin>>position;
  loopHere(head,end,position);

  head=removeLoop(head);
  Node *ptr=head;
  
  while(ptr){
    cout<<ptr->data<<' ';
    ptr=ptr->next;
  }
}