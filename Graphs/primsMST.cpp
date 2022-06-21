#include <bits/stdc++.h>
using namespace std;
#define ll long long int


//function to find out minimum key value
//from the set of vertices not included in MST
int minKey(vector<int> key, vector<bool> mstSet){
    int min=INT_MAX;
    int min_index;

    for(int i=0;i<key.size();i++){
        if(mstSet[i]==false and key[i]<min){
            min=key[i];
            min_index=i;
        }
    }
    return min_index;
}
//function to print MST
void printMST(vector<int> parent, vector<vector<int>> adj){
    cout<<"Edge \tWeight\n";
    for(int i=1;i<parent.size();i++){
        cout<<parent[i]<<"-"<<i<<" \t"<<adj[i][parent[i]]<<'\n';
    }
}
//function to construct and print MST
//for a given graph through adjacency matrix
void primMST(vector<vector<int>> adj){
    
    int v=adj.size();

    //array to strore constructed MST 
    vector<int> parent(v,0);

    //key values 
    //indicates minimum weight edge connected to that node
    vector<int> key(v,INT_MAX);

    //to indicate set of vertices included in MST
    vector<bool> mstSet(v,false);

    key[0]=0; //mst will contain 0 as a first node
    parent[0]=-1; //root node of MST

    //mst will have v vertices, i.e. v-1 edges
    for(int i=0;i<v-1;i++){

        //u is vertex with minimum key value 
        //not included in MST
        int u = minKey(key,mstSet);

        mstSet[u]=true;

        //update key value of all adjacent vertices of u
        //which are not present in MST
        //update parent index of them
        for(int j=0;j<v;j++){
            //adj[u][j]!=0 implies there is and edge b/w u and j
            //mstSet[j]==false implies that this node is not visited before
            //finally if its value is less than currrent key
            if(adj[u][j]!=0 and mstSet[j]==false and adj[u][j]<key[j]){
                parent[j]=u;
                key[j]=adj[u][j];
            }
        }
    }

    printMST(parent,adj);

}

//can be done in an efficient manner if adjacency list provided
//how?
//see we need to mainain or keep track of element with 
//lowest key value
//why cant we use min-priority queue here?

//lets do that

void printMSTAdjLst(vector<int> parent, vector<vector<int>> adj[]){
    cout<<"Edge \tWeight\n";
    for(int i=1;i<parent.size();i++){
        cout<<parent[i]<<"-"<<i<<" \t"<<adj[i][parent[i]][1]<<'\n';
    }
}

void primMSTAdjList(int v, vector<vector<int>> adj[]){
    //adj is adj list
    //every element of list is {vertex,weight};

    vector<int> key(v,INT_MAX);
    vector<int> mstSet(v,false);

    vector<int> parent(v,0);
    //priority queue {weight,vertex}
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        mstSet[u]=true;

        //iterate over adj list of u
        // check which element is not visited previously
        // and has weight<key[x]
        // so update that
        for(auto &it: adj[u]){
            int x=it[0]; //vertex
            int weight=it[1]; //weight
            
            if(mstSet[x]==false and weight<key[x]){
                key[x]=weight;
                pq.push({weight,x});
                parent[x]=u;
            }
        }
    }
    printMSTAdjLst(parent,adj);
}

int main(){
    vector<vector<int>> adj = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    primMST(adj);
    return 0;
}
