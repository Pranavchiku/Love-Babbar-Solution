#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isSafe(vector<vector<int>> board, int row, int col, int n){
    //check for the left and right of row
    for(int i=0; i<col; i++){
        if(board[row][i] == 1)
            return false;
    }
    //check for the diagonal element
    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 1)
            return false;
    }

    for(int i=row, j=col; i<n && j>=0; i++, j--){
        if(board[i][j] == 1)
            return false;
    }

    return true;
}
bool solve(vector<vector<int>> &board, vector<vector<int>> &result, int col, int n){
    if(col==n){
        vector<int> v;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    v.push_back(j+1);
                }
            }
        }
        result.push_back(v);
        return true;
    }

    bool res=false;
    for(int i=0;i<n;i++){
        if(isSafe(board,i,col,n)){
            board[i][col]=1;
            res=solve(board,result,col+1,n) || res;
            board[i][col]=0; //backtrack
        }
    }

    return res;

}
vector<vector<int>> nQueen(int n) {
    vector<vector<int>> result;
    vector<vector<int>> board(n,vector<int>(n,0));

    if(!solve(board,result,0,n)){
        return {};
    }
    sort(result.begin(),result.end());
    return result;
}
int main(){
    return 0;
}