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

    //try all colors
    for(int j=0;j<m;j++){
        //if color j is safe
        if(isSafe(i,j,graph,v,color)){
            //assign color j to node i
            color[i]=j;
            //recurse for next node
            if(func(graph,m,v,i+1,color)) return true;
            //backtrack, unassign color j from node i
            //and try next color
            color[i]=-1;
        }
    }
    return false;
}
//given graph and m colors
//task is to find can the given graph be colored using
//n colors, such that not two adjacent vertices have same color
bool graphColoring(bool graph[101][101], int m, int n) {
    
    //create a vector color
    //representing color of each vertex
    vector<int> color(n);

    //initialise all color to -1 i.e. not colored
    for(int i=0;i<n;i++) color[i]=-1;

    return func(graph,m,n,0,color);

}