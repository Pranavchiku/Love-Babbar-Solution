#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void printPath(map<pair<int,int>,pair<int,int>>mp, pair<int,int> u){
    if(u.first==0 and u.second==0){
        cout<<u.first<<" "<<u.second<<endl;
        return;
    }
    printPath(mp,mp[u]);
    cout<<u.first<<" "<<u.second<<endl;
}

void bfs(int a, int b, int target){
    map<pair<int,int>,int> m; //to keep track of visited pairs
    bool isSolvable=false;

    map<pair<int,int>,pair<int,int>> mp; //keeps track of previous pair

    queue<pair<int,int>> q;

    q.push({0,0});
    while(!q.empty()){
        auto u=q.front();
        q.pop();

        if(m[u]==1) continue; //if already visited

        if((u.first>a || u.second>b || u.first<0 || u.second<0)) continue; //if out of bounds

        m[{u.first,u.second}]=1; //mark as visited

        if(u.first==target || u.second==target){
            isSolvable=true;
            printPath(mp,u);
            if(u.first==target){
                if(u.second!=0){
                    cout<<u.first<<" "<<0<<'\n'; //emptying jug 2
                    return ;
                }
                
            }
            else{
                if(u.first!=0){
                    cout<<0<<" "<<u.second<<'\n'; //emptying jug 1
                    return ;
                }
            }
        }

        //push all possible moves

        //first - completely fill jug 2
        //check if it is already not visited
        //then fill it and make parent of it as u
        if(m[{u.first,b}]!=1){
            q.push({u.first,b});
            mp[{u.first,b}]=u;
        }

        //completely fill the jug 1
        //check if it is already not visited
        //then fill it and make parent of it as u
        if(m[{a,u.second}]!=1){
            q.push({a,u.second});
            mp[{a,u.second}]=u;
        }

        //transfer from jug 1 to jug 2
        int d=b-u.second; //available space to fill
        if(u.first>=d){
            int c=u.first-d; //remaining water in jug 1
            if(m[{c,b}]!=1){
                q.push({c,b});
                mp[{c,b}]=u;
            }
        }
        else{
            int c=u.first+u.second; //empty the jug 1 and fill 2
            if(m[{0,c}]!=1){
                q.push({0,c});
                mp[{0,c}]=u;
            }
        }

        //transfer from jug 2 to jug 1
        d = a-u.first; //available space to fill
        if(u.second>=d){
            int c=u.second-d; //remaining water in jug 2
            if(m[{a,c}]!=1){
                q.push({a,c});
                mp[{a,c}]=u;
            }
        }
        else{
            int c=u.second+u.first;
            if(m[{c,0}]!=1){
                q.push({c,0});
                mp[{c,0}]=u;
            }
        }

        //empty jug 2
        if(m[{u.first,0}]!=1){
            q.push({u.first,0});
            mp[{u.first,0}]=u;
        }

        //empty jug 1
        if(m[{0,u.second}]!=1){
            q.push({0,u.second});
            mp[{0,u.second}]=u;
        }

    }

    if(!isSolvable){
        cout<<"Impossible"<<endl;
        return;
    }
}

int main(){
    int a,b,target;
    cin>>a>>b>>target;
    bfs(a,b,target);
}