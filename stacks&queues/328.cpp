#include <bits/stdc++.h>
using namespace std;
#define ll long long int

typedef struct Node{
    int time;
    int i;
    int j;
}Node;
int orangesRotting(vector<vector<int>>& grid) {

    queue<Node*> q;
    int x=grid.size();
    int m=grid[0].size();


    for(int i=0;i<x;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                Node *n=new Node;
                n->time=0;
                n->i=i;n->j=j;
                q.push(n);
            }
        }
    }
    int time=0;
    while(!q.empty()){
        Node *n=q.front();
        int tempi=n->i;
        int tempj=n->j;
        cout<<tempi<<' '<<tempj<<'\n';
        time=n->time;
        if(tempi-1>=0 and tempj-1>=0){
            if(grid[tempi-1][tempj]==1){
                Node *a=new Node;
                a->time=n->time+1;
                a->i=tempi-1;
                a->j=tempj;
                q.push(a);

                grid[tempi-1][tempj]=2;
            }
            if(grid[tempi][tempj-1]==1){
                Node *a=new Node;
                a->time=n->time+1;
                a->i=tempi;
                a->j=tempj-1;
                q.push(a);
                grid[tempi][tempj-1]=2;
            }
        }
        else if(tempi-1>=0 and tempj-1<0){
            if(grid[tempi-1][tempj]==1){
                Node *a=new Node;
                a->time=n->time+1;
                a->i=tempi-1;
                a->j=tempj;
                q.push(a);
                grid[tempi-1][tempj]=2;

            }
        }
        else if(tempi-1<0 and tempj-1>=0){
            if(grid[tempi][tempj-1]==1){
                Node *a=new Node;
                a->time=n->time+1;
                a->i=tempi;
                a->j=tempj-1;
                q.push(a);
                grid[tempi][tempj-1]=2;
            }
        }
        else if(tempi+1<x and tempj+1<m){
            if(grid[tempi+1][tempj]==1){
                Node *a=new Node;
                a->time=n->time+1;
                a->i=tempi+1;
                a->j=tempj;
                q.push(a);
                grid[tempi+1][tempj]=2;
            }
            if(grid[tempi][tempj+1]==1){
                Node *a=new Node;
                a->time=n->time+1;
                a->i=tempi;
                a->j=tempj+1;
                q.push(a);
                grid[tempi][tempj+1]=2;
            }
        }
        else if(tempi+1>=x and tempj+1<m){
            if(grid[tempi][tempj+1]==1){
                Node *a=new Node;
                a->time=n->time+1;
                a->i=tempi;
                a->j=tempj+1;
                q.push(a);
                grid[tempi][tempj+1]=2;
            }
        }
        else if(tempi+1<x and tempj+1>=m){
            cout<<"here"<<'\n';
            if(grid[tempi+1][tempj]==1){
                Node *a=new Node;
                a->time=n->time+1;
                a->i=tempi+1;
                a->j=tempj;
                q.push(a);
                grid[tempi+1][tempj]=2;
            }
        }
        q.pop();
    }


    for(int i=0;i<x;i++){
        for(int j=0;j<m;j++){
            cout<<grid[i][j]<<' ';
        }
        cout<<'\n';
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1) return -1;
        }
    }

    return time;
}
int main(){
    vector<vector<int>> grid={{{0,1,2},{0,1,2},{2,1,1}}};
    cout<<orangesRotting(grid)<<'\n';
    return 0;
}