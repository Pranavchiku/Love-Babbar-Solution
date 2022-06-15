#include <bits/stdc++.h>
using namespace std;
#define ll long long int

queue<int> interleave(queue<int> q, int n){
    stack<int> s;

    int half=n/2;
    for(int i=0;i<half;i++){
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    
    for(int i=0;i<half;i++){
        q.push(q.front());
        q.pop();
    }

    for(int i=0;i<half;i++){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
    return q;
}

int main(){

    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    queue<int> q2=interleave(q,q.size());
    int length = q2.size();
    for (int i = 0; i < length; i++) {
        cout << q2.front() << " ";
        q2.pop();
    }
    return 0;
}