#include<bits/stdc++.h>
using namespace std;

//reverse stack using recursion

void insertAtBottom(stack<int> &s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int temp=s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(temp);
}
void reverseStack(stack<int> &s){
    if(s.size()>0){
        int x=s.top();
        s.pop();
        reverseStack(s);

        insertAtBottom(s,x);
    }
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    reverseStack(s);
    while(!s.empty()){
        cout<<s.top()<<' ';
        s.pop();
    }
    cout<<'\n';
}