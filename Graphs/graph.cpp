#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Graph
{
    int v; //No. of vertices

    //Pointer to an array contating adjaceny lists
    vector<vector<int>> adj;

    //store indegree of each vertex
    vector<int> indegree;
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

        //to check if cycle is present or not
        bool isCyclic();

        //helper function to check cycle
        //pass a source and visited map
        bool isCyclicHelper(int v, bool visited[], bool *recStack);

        //topological sorting helper function
        void topologicalSortHelper(int s, map<int,bool> &visited, stack<int> &stack);

        //topological sort
        void topologicalSort();

        //helper function for allTopologicalSort
        void allTopoSortHelper(vector<int> &res, vector<bool> &visited);

        //alltoplogical sort
        //use indegree
        void allTopoSort();
};

Graph:: Graph(int v){
    this->v=v;
    adj.resize(v);

    //initialise all indegree to 0
    for(int i=0;i<v;i++) indegree.push_back(0);
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w); //add w to v's list

    indegree[w]++;//adding indegree
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

bool Graph::isCyclicHelper(int s, bool visited[], bool *recStack)
{
    if(visited[s] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[s] = true;
        recStack[s] = true;
  
        // Recur for all the vertices adjacent to this vertex
        for( auto &it : adj[s]){
            if(!visited[it] and isCyclicHelper(it,visited,recStack)){
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

bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
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
        if ( !visited[i] && isCyclicHelper(i, visited, recStack))
            return true;
  
    return false;
}

void Graph::topologicalSortHelper(int s, map<int,bool> &visited, stack<int> &stack){
    visited[s]=true;

    for(auto &it: adj[s]){
        if(!visited[it]){
            topologicalSortHelper(it,visited,stack);
        }
    }
    stack.push(s);
}

void Graph::topologicalSort(){
    map<int,bool> visited;

    stack<int> stack;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            topologicalSortHelper(i,visited,stack);
        }
    }
    while(!stack.empty()){
        cout<<stack.top()<<' ';
        stack.pop();
    }
    cout<<'\n';
}

void Graph::allTopoSortHelper(vector<int> &res, vector<bool> &visited){
    bool flag=false;
    for(int i=0;i<v;i++){
        //check if indegree is 0
        //and not visited before
        if(indegree[i]==0 and !visited[i]){
            //decrease the indegree of elements
            //in adjacency list of i
            // i.e. intutively we are deleting node i
            // and then finding topoSort of remaining elements

            for(auto &it: adj[i]){
                indegree[it]--;
            }

            res.push_back(i);
            visited[i]=true;
            allTopoSortHelper(res,visited);

            //then once all are done
            //backtrack it and make all values same

            visited[i]=false;
            res.erase(res.end()-1);
            for(auto &it: adj[i]){
                indegree[it]++;
            }
            
            //this flag indicates whether all topological sort
            //done or not
            flag=true;
        }

    }

    //we reach here if all vertices are visited
    // and alltopological sort is found
    if(!flag){
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<' ';
        }
        cout<<'\n';
    }
}

void Graph::allTopoSort(){
    vector<bool> visited(v,false);
    vector<int> res;
    allTopoSortHelper(res,visited);
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
    g.addEdge(5, 0);
    g.addEdge(5, 2);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    // g.addEdge(3, 3);
    // g.addEdge(4, 5);
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(5);
    cout<<"\n";

    cout << "Following is Depth First Traversal "
         << "(starting from vertex 0) \n";
    map<int,bool> visited;
    g.DFSDisconnected(visited);
    cout<<'\n';

    visited.clear();
    cout<<g.isCyclic()<<'\n';

    g.topologicalSort();

    g.allTopoSort();
    return 0;
}
