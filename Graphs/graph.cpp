#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Graph
{
    int v; //No. of vertices

    //Pointer to an array contating adjaceny lists
    vector<vector<int>> adj;

    public:
        Graph(int v); //constructor

        //function to add an edge to graph
        void addEdge(int v, int w);

        //print BFS traversal from a given source vertex
        void BFS(int s);

        //print DFS traversal from a given source vertex
        //and an visited map
        void DFS(int s, map<int,bool> &visited);

        //print DFS for disconnected graph
        void DFSDisconnected(map<int,bool> &visited);
};

Graph:: Graph(int v){
    this->v=v;
    adj.resize(v);
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w); //add w to v's list
}


// This will only print the BFS of connected graph
void Graph::BFS(int s){
    map<int, bool> visited; //vertex as int and bool if visited or not
    queue<int> q;

    visited[s]=true;
    q.push(s);

    while(!q.empty()){
        s=q.front();
        cout<<s<<' ';
        q.pop();

        for(auto vertex: adj[s]){
            if(!visited[vertex]){
                visited[vertex]=true;
                q.push(vertex);
            }
        }
    }

}

void Graph::DFS(int s, map<int, bool> &visited){
    visited[s]=true;
    cout<<s<<' ';

    for(auto& it: adj[s]){
        if(!visited[it]){
            DFS(it,visited);
        }
    }
}

void Graph:: DFSDisconnected(map<int, bool> &visited){
    for(int i=0;i<adj.size();i++){
        if(!visited[i]){
            DFS(i,visited);
        }
    }
}
//For disconnected graph

vector<int> bfsDisconnected(int v, vector<int> adj[]){
    vector<int> bfs;
    vector<bool> visited(v,false);

    //traverse on nodes irrespective of any connection
    for(int i=0;i<v;i++){
        //check if visited or not
        if(!visited[i]){
            //bfs for that node if not already visited
            queue<int> q;
            visited[i]=true;
            q.push(i);
            while(!q.empty()){
                int curr=q.front();
                q.pop();
                bfs.push_back(curr);
                for(auto it: adj[curr]){
                    if(!visited[it]){
                        visited[it]=true;
                        q.push(it);
                    }
                }
            }
        }
    }
    return bfs;
}   

int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(4, 5);
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(1);
    cout<<"\n";

    cout << "Following is Depth First Traversal "
         << "(starting from vertex 2) \n";
    map<int,bool> visited;
    g.DFSDisconnected(visited);
    cout<<'\n';
    return 0;
}