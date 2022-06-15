#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//Stack from scratch


//Using Array

typedef struct Stack{
    int size;
    int top;
    int *arr;
} STACK;

bool isEmpty(STACK *ptr){
    if(ptr->top==-1) return true;
    else return false;
}

bool isFull(STACK *s){
    if(s->top==s->size-1) return true;
    else return false;
}

void push(STACK *s, int elem){
    if(isFull(s)) cout<<"Stack Overflow"<<'\n';
    else{
        s->top++;
        s->arr[s->top]=elem;
    }
}

void pop(STACK *s){
    if(isEmpty(s)) cout<<"Stack underflow"<<'\n';
    else{
        int temp=s->arr[s->top];
        s->top--;
        cout<<temp<<'\n';
    }
}

int top(STACK *s){
    if(isEmpty(s)) return -1;
    else return s->arr[s->top];
}

int main(){
    STACK *s=new(Stack);
    int n;cin>>n;

    s->size=n;
    s->top=-1;
    s->arr=(int *) malloc(s->size*sizeof(int));

    push(s,89);
    push(s,90);
    pop(s);
    cout<<top(s)<<'\n';
}