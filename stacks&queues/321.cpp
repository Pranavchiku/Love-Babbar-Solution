#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class kQueues{
    int *arr;
    int *front;
    int *rear;
    int *next;
    int n,k;
    int free;


    public:
        kQueues(int k, int n);

        bool isFull() { 
            return (free==-1);
        }

        //enqueue item in queue qn
        void enqueue(int item, int qn);

        int dequeue(int qn); // dequeue form queueu qn

        bool isEmpty(int qn){
            return (front[qn]==-1);
        }

};

kQueues::kQueues(int k1, int n1){
    k=k1;n=n1;
    arr=new int[n];
    front=new int[k];
    rear=new int[k];
    next=new int[n];

    //initialize all queues as empty
    for(int i=0;i<k;i++) front[i]=-1;

    //initialize all free spaces
    free=0;
    for(int i=0;i<n-1;i++) next[i]=i+1;
    next[n-1]=-1;
}

void kQueues::enqueue(int item, int qn){
    //check overflow
    if(isFull()){
        cout<<"Queue overflow"<<'\n';
        return;
    }
    int i=free;
    free=next[i];

    if(isEmpty(qn)) front[qn]=i;
    else next[rear[qn]]=i;

    next[i]=-1;

    rear[qn]=i;

    arr[i]=item;
}

int kQueues::dequeue(int qn){
    //check underflow
    if(isEmpty(qn)){
        cout<<"Queue underflow"<<'\n';
        return -1;
    }
    int i=front[qn];
    front[qn]=next[i];
    next[i]=free;
    free=i;

    return arr[i];
}