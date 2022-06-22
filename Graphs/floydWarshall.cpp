#include <bits/stdc++.h>
using namespace std;
#define ll long long int


//floydWarshall is used for finding all shortest paths
//i.e. shortest path from all vertex to all reachable vertex
//given is adjacency matrix
void floydWarshall(vector<vector<int>> &graph){

    int v=graph.size();
    int dist[v][v];

    //initialise dist matrix
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            dist[i][j]=graph[i][j];
        }
    }
    //will start with intermediate vertices
    //i.e. k={0,1,2,3,....,v-1}
    for(int k=0;k<v;k++){
        //iterate through all source vertices
        for(int i=0;i<v;i++){
            //here i represent source vertex
            //and k represent intermediate vertex
            //iterate through all destination vertices
            for(int j=0;j<v;j++){
                //here j represent destination vertex

                //check if k can be intermidate between i and j
                //by checking graph[k][j]!=INF and graph[i][k]!=INF
                //check if there is a shorter path from i to j
                //by checking graph[i][j]>graph[i][k]+graph[k][j]
                //if there is a shorter path then update the distance

                if(dist[i][j]>dist[i][k]+dist[k][j] and (dist[i][k]!=INT_MAX and dist[k][j]!=INT_MAX)){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }

    //print the shortest path from all source to all destination
    //i.e. shortest path from all vertex to all reachable vertex
    cout<<"Source \tDistance"<<'\n';
    for(int i=0;i<v;i++){
        cout<<i<<" \t";
        for(int j=0;j<v;j++){
            if(graph[i][j]!=INT_MAX){
                cout<<dist[i][j]<<' ';
            }
            else cout<<"INF"<<' ';
        }
        cout<<"\n";
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>> graph(v,vector<int>(v,INT_MAX));
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v]=w;
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(i==j) graph[i][j]=0;
        }
    }
    floydWarshall(graph);
}