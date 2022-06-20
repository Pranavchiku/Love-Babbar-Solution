#include <bits/stdc++.h>
using namespace std;
#define ll long long int

typedef struct Node{
    int data;
    struct Node* next;
    Node(int x){
    data = x;
    next = NULL;
	}
}Node;




Node* insertAtHead(Node *head, int data){
    Node* ptr = new Node(data);
    ptr->next=head;
    ptr->data=data;
    return ptr;
}

Node *insertAtEnd(Node *end, int data){
    Node* ptr= new Node(data);
    ptr->data=data;
    ptr->next=NULL;
    
    end->next=ptr;
    return ptr;
}
void linkedlistTraversal(Node *ptr, priority_queue<int, vector<int>, greater<int>> &q){
    while(ptr!=NULL){
        q.push(ptr->data);
        ptr=ptr->next;
    }
}
Node * mergeKLists(Node *arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0;i<n;i++){
        linkedlistTraversal(arr[i],q);
    }
    Node *head = new Node(q.top());
    Node *end=head;
    q.pop();
    while(!q.empty()){
        end=insertAtEnd(end,q.top());
        q.pop();
    }
    return head;
} 
int main(){


    int n;cin>>n;
    int temp;cin>>temp;
    
    Node *head = new Node(temp);
    Node *end=head;
    for(int i=1;i<n;i++){
        cin>>temp;
        end=insertAtEnd(end,temp);
    }

    cin>>n;
    cin>>temp;
    Node *head2=new Node(temp);
    Node *end2=head2;
    for(int i=1;i<n;i++){
        cin>>temp;
        end2=insertAtEnd(end2,temp);
    }
    // linkedlistTraversal(head);
    // linkedlistTraversal(head2);

    cin>>n;
    cin>>temp;
    Node *head3=new Node(temp);
    Node *end3=head3;
    for(int i=1;i<n;i++){
        cin>>temp;
        end3=insertAtEnd(end3,temp);
    }

    Node *arr[3]={head,head2,head3};
    Node *out=mergeKLists(arr,3);

    
    return 0;
}