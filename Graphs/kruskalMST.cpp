#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class DSU{

    int *parent;
    int *rank;

    public:
        //constructor to initialise the parent and rank array
        DSU(int n){
            parent=new int[n];
            rank=new int[n];
            
            for(int i=0;i<n;i++){
                parent[i]=-1;
                rank[i]=1;
            }
        }

        //find function
        //to find the parent of the subset
        int find(int i){
            if(parent[i]==-1) return i;
            return parent[i]=find(parent[i]);
        }

        //union function by rank
        //if xrank<yrank then make x a child of y
        void unite(int x, int y){
            //find parent of both nodes
            int s1=find(x); 
            int s2=find(y);
            //find rank of the parents
            if(s1!=s2){
                if(rank[s1]<rank[s2]){
                    parent[s1]=s2;
                    rank[s2]+=rank[s1];
                }
                else{
                    parent[s2]=s1;
                    rank[s1]+=rank[s2];
                }
            }
        }
};

class Graph{
    vector<vector<int>> edgelist;
    int v;
    public:
        Graph(int v){
            this->v=v;
        }
        void addEdge(int x, int y, int w){
            //edge b/w x->y with weight w
            edgelist.push_back({w,x,y});
        }

        void kruskalMST(){
            //sort edges by weight;
            sort(edgelist.begin(),edgelist.end());

            //initialise the DSU;
            DSU s(v);
            int ans=0;
            cout << "Following are the edges in the "
                "constructed MST"
             << endl;
            for(auto &edge: edgelist){
                int w=edge[0];
                int x=edge[1];
                int y=edge[2];

                //take that edge in MST if it donot form a cycle
                if(s.find(x)!=s.find(y)){
                    s.unite(x,y);
                    ans+=w;
                    cout << x << " -- " << y << " == " << w
                     << endl;

                }
            }
            cout << "Minimum Cost Spanning Tree: " << ans;
        }
};

int main()
{
    /* Let us create following weighted graph
                   10
              0--------1
              |  \     |
             6|   5\   |15
              |      \ |
              2--------3
                  4       */
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);
 
    // int n, m;
    // cin >> n >> m;
 
    // Graph g(n);
    // for (int i = 0; i < m; i++)
    // {
    //     int x, y, w;
    //     cin >> x >> y >> w;
    //     g.addEdge(x, y, w);
    // }
 
    g.kruskalMST();
    return 0;
}