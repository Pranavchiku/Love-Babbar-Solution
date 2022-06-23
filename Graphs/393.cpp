#include <bits/stdc++.h>
using namespace std;
#define ll long long int


bool isSafe(int i, int j, bool graph[101][101], int v, vector<int> color){
    //no neighbouring node must have same color
    for(int k=0;k<v;k++){
        if(graph[i][k]==1 and color[k]==j){
            return false;

        }
    }
}
bool func(bool graph[101][101], int m, int v, int i, vector<int> &color){
    if(i==v) return true;

    for(int j=0;j<m;j++){
        if(isSafe(i,j,graph,v,color)){
            color[i]=j;
            if(func(graph,m,v,i+1,color)) return true;
            color[i]=-1;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    
    vector<int> color(n);
    for(int i=0;i<n;i++) color[i]=-1;


    return func(graph,m,n,0,color);

}