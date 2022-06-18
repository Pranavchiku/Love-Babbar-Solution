#include <bits/stdc++.h>
using namespace std;
#define ll long long int


typedef struct Node{
    int data;
    Node* left;
    Node* right;
}Node;

Node* createNode(int data){
    Node *n=new(Node);
    n->right=n->left=NULL;
    n->data=data;

    return n;
}

void insert(Node *root, int key){
    Node* prev=NULL;
    Node *n=createNode(key);
    while(root!=NULL){
        prev=root;
        if(key==root->data) return;
        else if(key<root->data) root=root->left;
        else root=root->right;
    }
    if(key>prev->data) prev->right=n;
    else prev->left=n;
}

int inOrder(Node *root, int &count){
    if(root!=NULL){
        inOrder(root->left,count);
        count++;
        inOrder(root->right,count);
    }
}

void ithElement(Node *root, int i, int &count, int &ans){
    if(root!=NULL){
        ithElement(root->left,i,count,ans);
        count++;
        // cout<<count<<' '<<root->data<<'\n';
        // cout<<i<<'\n';
        if(count==i){
            // cout<<"here"<<'\n';
            ans=root->data;
        }
        ithElement(root->right,i,count,ans);
    }
}
int median(Node *root){
    int n=0; //number of elements
    inOrder(root,n);
    // cout<<n<<'\n';
    if(n%2!=0){
        int count=0;
        int i=(n+1)/2;
        int ans=0;
        // cout<<i<<'\n';
        ithElement(root,i,count,ans);
        return ans;
    }
    else{
        int count=0;
        int firstElem=0;
        ithElement(root,(n/2),count,firstElem);
        count=0;
        int secElem=0;
        ithElement(root,(n/2)+1,count,secElem);
        return ((firstElem+secElem)/2);
    }
}
int main(){
    int n;cin>>n;
    int temp;cin>>temp;
    Node *root=createNode(temp);
    for(int i=1;i<n;i++){
        cin>>temp;
        insert(root,temp);
    }
    cout<<median(root)<<'\n';
}