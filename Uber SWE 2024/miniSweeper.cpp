#include<bits/stdc++.h>
using namespace std;

/*
Minisweeper -> 3 levels

level of difficulty will be selected by user -> {easy, medium, hard} -> {1,2,3}
1. Easy -> 9*9 board -> 10 Mines -> 10/81
2. Medium -> 16*16 board -> 40 Mines -> 40/256
3. Hard -> 24*24 board -> 99 Mines -> 99/279

class -> miniSweeper -> size of board (n)
                     -> number of mines (m, mapped through size)
                     -> track of all already visited places (visited)
                     -> n*n board with m mines
                     -> arrangement will be made to add m mines randomly such that no mine is placed 
                        on a cell which is already occupied by a mine
                     -> will start the game, take input from user which position he/she wants to click
                     -> will move as per rules of the game
*/

class MinSweeper{
    private:
        int sizeOfBoard;
        int numberOfMines;
        map<pair<int,int>,bool> visited;
        //1 -> mine, 0 -> no mine
        vector<vector<bool>> board;
    public:
        MinSweeper(int sizeOfBoard, int numberOfMines){
            this->sizeOfBoard=sizeOfBoard;
            this->numberOfMines=numberOfMines;
            this->board.resize(sizeOfBoard,vector<bool>(sizeOfBoard,false));
            this->visited.clear();
            //add mines randomly
            this->addMines();

            //start playing the game
            this->play();
        }

        MinSweeper(){
            cout<<"Welcome to Minsweeper"<<endl;
            cout<<"Select the level of difficulty"<<endl;
            cout<<"1 for Easy"<<endl;
            cout<<"2 for Medium"<<endl;
            cout<<"3 for Hard"<<endl;
            int level;cin>>level;

            if(level==1) MinSweeper(9,10);
            else if(level==2) MinSweeper(16,40);
            else if(level==3) MinSweeper(24,99);
            else{
                cout<<"Invalid level"<<endl;
                exit(0);
            }
        }
        void addMines(){
            int x, y;
            x=(rand() % (this->sizeOfBoard-1 - 0 + 1)) + 0;
            y=(rand() % (this->sizeOfBoard-1 - 0 + 1)) + 0;
            for(int i=0;i<this->numberOfMines;i++){
                while(board[x][y]==1){
                    x=(rand() % (this->sizeOfBoard-1 - 0 + 1)) + 0;
                    y=(rand() % (this->sizeOfBoard-1 - 0 + 1)) + 0;
                }
                board[x][y]=1;
                x=(rand() % (this->sizeOfBoard-1 - 0 + 1)) + 0;
                y=(rand() % (this->sizeOfBoard-1 - 0 + 1)) + 0;
            }
            return;
        }
        void visitedPlaces(){
            for(auto it: this->visited){
                cout<<it.first.first<<" "<<it.first.second<<endl;
            }
        }
        
        bool isValid(int x, int y){
            if(x<0 or x>=this->sizeOfBoard or y<0 or y>=this->sizeOfBoard or visited.find({x,y})!=visited.end()){
                return false;
            }
            return true;
        }
        void checkAdjacentSides(int x, int y){
            vector<pair<int,int>> adj={ {-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1} };
            
            int bombCount=0;
            for(auto it: adj){
                int newX=x+it.first;
                int newY=y+it.second;
                if(isValid(newX,newY)){
                    if(board[newX][newY]==1){
                        bombCount++;
                    }
                }
            }
            if(bombCount!=0){
                cout<<"You have "<<bombCount<<" bombs adjacent to you"<<endl;
                return;
            }
            else{
                cout<<"You have no bombs adjacent to you, wohoo!!! All the adjacent blocks are opened"<<endl;
                for(auto it: adj){
                    int newX=x+it.first;
                    int newY=y+it.second;
                    if(isValid(newX,newY)){
                        visited[{newX,newY}]=true;
                    }
                }
                return;
            }
            
        }
        void play(){
            cout<<"We are all set to start, Lets Begin!! Have a good luck!"<<'\n';
            int x,y;
            while(visited.size()!=(this->sizeOfBoard*this->sizeOfBoard)-this->numberOfMines){
                cout<<"Already visited blocks: "<<'\n';
                this->visitedPlaces();
                cout<<"Enter the x and y coordinates of the cell you want to click: ";
                cin>>x>>y;
                cout<<'\n';

                if(board[x][y]==1){
                    cout<<"BOOM!! You have hit a mine, Game Over!!"<<'\n';
                    return;
                }
                else{
                    //check for adjacent sides
                    this->checkAdjacentSides(x,y);
                }
            }
        }
};

int main(){
    MinSweeper game;
    return 0;
}