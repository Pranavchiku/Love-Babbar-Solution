#include <bits/stdc++.h>
using namespace std;
#define ll long long int


//function to find out vertex with minimum distance
//from source
int minDistance(vector<int> dist, vector<bool> sptSet){
    int min=INT_MAX, min_index;

    for(int i=0;i<dist.size();i++){
        if(sptSet[i]==false and dist[i]<=min){
            min=dist[i];
            min_index=i;
        }
    }
    return min_index;
}

//function to print SPT
void printSPT(vector<int> parent, vector<vector<int>> adj[]){
    cout<<"Edge \tWeight\n";
    for(int i=1;i<parent.size();i++){
        cout<<parent[i]<<"-"<<i<<" \t"<<adj[i][parent[i]][1] <<'\n';
    }
}

//function to print minimum distance of each vertex
//from source

void distEachVertex(vector<int>dist){
    cout<<"Source \tVertex \tdistance"<<'\n';
    for(int i=0;i<dist.size();i++){
        cout<<0<<" \t"<<i<<" \t"<<dist[i]<<'\n';
    }
}

//function to implement dijkstra's algorithm
//graph is represented as an adjacency list
//adjacency list contains a list of {vertex, weight} pairs
void dijkstra(int v, vector<vector<int>> adj[], int src){
    //array to store distance of each vertex from src
    vector<int> dist(v,INT_MAX);

    //array to store parent of each vertex
    vector<int> parent(v,0);

    //to keep the track of vertex included in SPT
    vector<bool> sptSet(v,false);

    //initialize distance of src from src to 0
    dist[src]=0;

    //iterate through all vertices
    for(int i=0;i<v-1;i++){
        //u is vertex with minimum distance from src

        int u = minDistance(dist,sptSet);

        //include u in SPT
        sptSet[u]=true;

        //iterate over adj list of u
        //update the dist of those vertices which are not in SPT
        for(auto &it: adj[u]){
            int weight=it[1];
            int vertex=it[0];


            //update the distance of vertex if it is not in SPT
            //and distance of u+weight is less than current distance
            if(!sptSet[vertex] and dist[u]+weight<=dist[vertex]){
                dist[vertex]=dist[u]+weight;
                parent[vertex]=u;
            }

        }
        
        
    }

    //print distance of each vertex from source
    distEachVertex(dist);

    //print the created SPT
    printSPT(parent,adj);
}


//the above approach works in O(V^2) time
//how can we improve this?

//see at every step we actually need to find
//the vertex with minimum distance from src
//so why cant we use a min priority queue here?

//lets do that

void dijkstraEdd(int v, vector<vector<int>> adj[], int src){
    
    vector<int> dist(v,INT_MAX);

    vector<int> parent(v,0);

    vector<bool> sptSet(v,false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    //priority_queue with {distance, vertex}

    pq.push({0,src});

    dist[src]=0;
    while(!pq.empty()){

        //rather than calling the minDistance function
        //to find the minimum distance vertex
        //we can directly call the top of the queue
        //as it is a min priority_queue
        int u=pq.top().second;
        int weight=pq.top().first;
        pq.pop();
        sptSet[u]=true;

        //iterate over adj list of u
        //update the dist of those vertices which are not in SPT
        for(auto &it: adj[u]){
            int vertex=it[0];
            int weigh=it[1];

            if(!sptSet[vertex] and dist[u]+weigh<=dist[vertex]){
                dist[vertex]=dist[u]+weigh;
                parent[vertex]=u;
                pq.push({dist[vertex],vertex});
            }

        }


    }

    //print distance of each vertex from source
    distEachVertex(dist);

}
int main(){
    int v;
    cin>>v;
    vector<vector<int>> adj[v]; //adjacency list
    for(int i=0;i<v;i++){ //iterate over all vertices
        int n;cin>>n; //how much edges are there for this vertex
        for(int j=0;j<n;j++){
            int v,w; //destination vertex and its weight
            cin>>v>>w;
            adj[i].push_back({v,w}); //push in adj list of i
            //this indicates a edge from i to v with weight w
        }
    }

    cout<<"\n";
    for(int i=0;i<v;i++){
        cout<<"Adjacency list of vertex "<<i<<"\n";
        for(auto&it2: adj[i]){
            cout<<it2[0]<<" "<<it2[1]<<"\n";
        }
    }
    cout<<"\n";
    dijkstraEdd(v,adj,0);
}