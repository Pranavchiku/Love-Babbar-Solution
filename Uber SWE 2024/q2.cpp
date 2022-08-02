#include<bits/stdc++.h>
using namespace std;
//simple have to create mst

class DSU {
    int* parent;
    int* rank;
  
public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];
  
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
  
    // Find function
    int find(int i)
    {
        if (parent[i] == -1)
            return i;
  
        return parent[i] = find(parent[i]);
    }
    // union function
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
  
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

int solution(int noOfCities, int noOfRoads, vector<vector<int>> &roadFees){
    vector<vector<int>> adj[noOfCities];
    for(int i=0;i<noOfRoads;i++){
        adj[roadFees[i][0]-1].push_back({roadFees[i][1]-1,roadFees[i][2]});
        adj[roadFees[i][1]-1].push_back({roadFees[i][0]-1,roadFees[i][2]});
    }

    DSU dsu(noOfCities);
    sort(roadFees.begin(),roadFees.end());

    int ans=0;
    
    // vector<int> key(noOfCities,INT_MAX);
    // vector<bool> mstSet(noOfCities,false);
    // vector<int> parent(noOfCities,-1);

    // key[0]=0;
    // parent[0]=-1;
    // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    // pq.push({0,0});

    // while(!pq.empty()){
    //     int u=pq.top().second;
    //     pq.pop();
    //     mstSet[u]=true;
    //     for(auto it: adj[u]){
    //         int x=it[0];
    //         int weight=it[1];

    //         if(mstSet[x]==false and weight<key[x]){
    //             key[x]=weight;
    //             pq.push({weight,x});
    //             parent[x]=u;
    //         }
    //     }
    // }

    // int sum=0;
    // for(int i=0;i<noOfCities;i++){
    //     sum|=key[i];
    // }

    // return sum;



}
int main(){
    int noOfCities, noOfRoads;
    cin >> noOfCities >> noOfRoads;
    vector<vector<int>> roadFees;
    for(int i = 0; i < noOfRoads; i++){
        vector<int> temp;
        for(int j = 0; j < 3; j++){
            int temp1;
            cin >> temp1;
            temp.push_back(temp1);
        }
        roadFees.push_back(temp);
    }
    cout << solution(noOfCities, noOfRoads, roadFees);
    return 0;
}