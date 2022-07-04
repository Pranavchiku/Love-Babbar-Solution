#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//dijkstras wont work for negative edges
//hence need for bellman ford

//function to print distance of all vertices form source
//vertex

void printArr(vector<int> dist){
    cout<<"Source \tVertex \tdistance"<<'\n';
    for(int i=0;i<dist.size();i++){
        cout<<0<<" \t"<<i<<" \t"<<dist[i]<<'\n';
    }
}
//main function to implement bellman ford
void bellManFord(int e, vector<vector<int>> edges, int v, int src){

    //initialise all distances from src to vertices to INT_MAX
    vector<int> dist(v,INT_MAX);

    //initialise dist of src as 0
    dist[src]=0;

    //iterate through all vertices 
    for(int i=1;i<=v-1;i++){
        //iterate thorugh all the edges 
        //and update the distance of vertices
        //if dist[v]<dist[u]+weight(u,v);
        for(int j=0;j<e;j++){

            int u=edges[j][0];
            int v=edges[j][1];

            int weight=edges[j][2];
            if(dist[u]!=INT_MAX and dist[v]>dist[u]+weight){
                dist[v]=min(dist[v],dist[u]+weight);
            }
        }
    }

    //check if there is a negative cycle
    //above iteration gurantees the shortest distance from source
    //if there is a negative cycle then dist[v]>dist[u]+weight(u,v)
    //return it contains negative cycles

    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int weight=edges[i][2];

        if(dist[u]!=INT_MAX and dist[v]>dist[u]+weight){
            cout<<"Graph contains negative cycle"<<'\n';
            return;
        }
    }

    //if there is no negative cycle
    printArr(dist);
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>> edges(e,vector<int>(3));
    for(int i=0;i<e;i++){
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }
    bellManFord(e,edges,v,0);
    return 0;
}