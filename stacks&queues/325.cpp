#include <bits/stdc++.h>
using namespace std;
#define ll long long int

queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    queue<int> q2;
    stack<int> st;
    int count=0;
    while(count<k){
        st.push(q.front());
        q.pop();
        count++;
    }

    while(!st.empty()){
        q2.push(st.top());
        st.pop();
    }

    while(!q.empty()){
        q2.push(q.front());
        q.pop();
    }


    return q2;
}

int main(){
    int n=5;int k=3;
    queue<int> q;
    q.push(1);q.push(2);q.push(3);q.push(4);q.push(5);
    queue<int> q2=modifyQueue(q,k);


    while(!q2.empty()){
        cout<<q2.front()<<' ';
        q2.pop();
    }
    cout<<'\n';
}