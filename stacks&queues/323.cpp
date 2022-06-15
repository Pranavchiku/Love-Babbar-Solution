#include <bits/stdc++.h>
using namespace std;
#define ll long long int

typedef  struct Node{
    int key;
    int val;
    struct Node *next;
    struct Node *prev;
}Node;

class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
    map<int,Node*> m;
    int currsize;
    int size;
    Node *left=NULL;
    Node *right=NULL;
    LRUCache(int cap)
    {
        currsize=cap;
        size=0;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {   
        if(m[key]!=NULL){
            int ans=m[key]->val;
            Node *temp=m[key];
            Node *p=left;
            if(p==temp){
                left=left->next;
            }
            else{
                while(p->next!=temp){
                    p=p->next;
                }
                p->next=temp->next;
                temp->next->prev=p;
            }

            Node *n=new(Node);
            right->next=n;
            n->prev=right;
            n->key=key;
            n->val=ans;
            right=n;

            return ans;
        }
        else return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if(size==0){
            Node *n=new(Node);
            n->key=key;
            n->val=value;
            n->next=NULL;
            n->prev=NULL;

            m.insert(pair<int,Node*>(key,n));
            size++;

            left=n;
            right=n;
        }
        else{
            // cout<<size<<'\n';
            if(size<currsize){
                if(m.find(key)!=m.end()){
                    m[key]->val=value;
                    Node *temp=m[key];
                    Node *p=left;
                    if(p==temp){
                        left=left->next;
                    }
                    else{
                        while(p->next!=temp){
                            p=p->next;
                        }
                        p->next=temp->next;
                        temp->next->prev=p;
                    }

                    Node *n=new(Node);
                    right->next=n;
                    n->prev=right;
                    n->key=key;
                    n->val=value;
                    right=n;
                }
                else{
                    Node *n=new Node;
                    right->next=n;
                    n->prev=right;
                    n->key=key;
                    n->val=value;
                    n->next=NULL;
                    right=n;
                    size++;

                    m.insert(pair<int,Node*>(key,n));

                    
                }
            }
            else{
                if(m.find(key)!=m.end()){
                    // cout<<"here"<<'\n';
                    m[key]->val=value;
                    Node *temp=m[key];
                    Node *p=left;
                    if(p==temp){
                        left=left->next;
                    }
                    else{
                        while(p->next!=temp){
                            p=p->next;
                        }
                        p->next=temp->next;
                        temp->next->prev=p;
                    }

                    Node *n=new(Node);
                    right->next=n;
                    n->prev=right;
                    n->key=key;
                    n->val=value;
                    right=n;
                }
                else{
                    left=left->next;
                    Node *n=new(Node);
                    right->next=n;
                    n->prev=right;
                    n->key=key;
                    n->val=value;
                    n->next=NULL;

                    right=n;

                    m.insert(pair<int,Node*>(key,n));

                }
            }
        }
    }

    void traversal(){
        Node* p=left;
        while(p!=right){
            cout<<p->key<<' '<<p->val<<'\n';
            p=p->next;
        }
        if(p==right) cout<<p->key<<' '<<p->val<<'\n';

    }

    void mapTraversal(){
        map<int, Node*>::iterator itr;
        for (itr = m.begin(); itr != m.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second->val
             << '\n';
        }
        cout << endl;
    }

};


int main(){
    LRUCache cache(2);
    cache.set(1,2);
    cache.set(2,3);
    cache.set(1,5);
    cache.set(1,7);

    // cache.set(6,7);
    // cout<<cache.get(4)<<'\n';
    // cache.traversal();

    return 0;
}