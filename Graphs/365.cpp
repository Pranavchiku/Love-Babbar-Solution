#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isValid(vector<vector<int>> image, vector<vector<int>> visited,int n, int m, int x, int y, int originalColor){
    if((x>=0 and x<n) and (y>=0 and y<m)){
        if(image[x][y]==originalColor and visited[x][y]==0)
            return true;
        else return false;
    }
    else return false;
}

void solve(vector<vector<int>>& image, vector<vector<int>> &visited, int n, int m, int sr, int sc, int newColor, int originalColor){
    if(image[sr][sc]!=originalColor) return;

    //up
    int newx=sr-1;
    int newy=sc;
    // cout<<"check"<<'\n';
    image[sr][sc]=newColor;
    if(isValid(image,visited,n,m,newx,newy,originalColor)){
        // image[newx][newy]=newColor;
        // cout<<"here"<<'\n';
        visited[newx][newy]=1;
        solve(image,visited,n,m,newx,newy,newColor,originalColor);
    }
    //left

    newx=sr;
    newy=sc-1;
    // cout<<"check2"<<'\n';

    if(isValid(image,visited,n,m,newx,newy,originalColor)){
        // image[newx][newy]=newColor;
        // cout<<"here2"<<'\n';
        visited[newx][newy]=1;

        solve(image,visited,n,m,newx,newy,newColor,originalColor);

    }
    //down
    newx=sr+1;
    newy=sc;
    // cout<<"check3"<<'\n';

    if(isValid(image,visited,n,m,newx,newy,originalColor)){
        // image[newx][newy]=newColor;
        // cout<<"here3"<<'\n';
        visited[newx][newy]=1;

        solve(image,visited,n,m,newx,newy,newColor,originalColor);

    }
    //right
    newx=sr;
    newy=sc+1;
    // cout<<"check4"<<'\n';

    if(isValid(image,visited,n,m,newx,newy,originalColor)){
        // image[newx][newy]=newColor;
        // cout<<"here4"<<'\n';
        visited[newx][newy]=1;

        solve(image,visited,n,m,newx,newy,newColor,originalColor);

    }

    return;
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int n=image.size();
    int m=image[0].size();

    vector<vector<int>> visited(n, vector<int>(m,0));
    int originalColor=image[sr][sc];
    solve(image,visited,n,m,sr,sc,newColor,originalColor);

    return image;
}

int main(){
    int n;cin>>n;
    int m;cin>>m;

    vector<vector<int>> image;
    for(int i=0;i<n;i++){
        vector<int> temp;
        int x;
        for(int j=0;j<m;j++){
            cin>>x;
            temp.push_back(x);
        }
        image.push_back(temp);
    }

    int sr;cin>>sr;
    int sc;cin>>sc;
    int newColor; cin>>newColor;
    vector<vector<int>> out=floodFill(image,sr,sc,newColor);
    cout<<'\n';
    for(auto &it: out){
        for(auto &it2: it){
            cout<<it2<<' ';
        }
        cout<<'\n';
    }
}