#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isCyclicHelper(int s, bool visited[], bool *recStack,vector<int> adj[])
{
    if(visited[s] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[s] = true;
        recStack[s] = true;
  
        // Recur for all the vertices adjacent to this vertex
        for( auto &it : adj[s]){
            if(!visited[it] and isCyclicHelper(it,visited,recStack,adj)){
                return true;
            }
            else if(recStack[it]){
                return true;
            }
        }
  
    }
    recStack[s] = false;  // remove the vertex from recursion stack
    return false;
}

bool isCyclic(int v, vector<int> adj[]) {
    // code here
    bool *visited = new bool[v];
    bool *recStack = new bool[v];
    for(int i = 0; i < v; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
  
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < v; i++)
        if ( !visited[i] && isCyclicHelper(i, visited, recStack,adj))
            return true;
  
    return false;
}