#include<bits/stdc++.h>
using namespace std;

class identifier{
    public:
        bool isSnake;
        bool isLadder;

    public:
        identifier(){}
        identifier(bool isSnake, bool isLadder){
            this->isSnake=isSnake;
            this->isLadder=isLadder;
        }
        bool getIsSnake(){
            return this->isSnake;
        }
        bool getIsLadder(){
            return this->isLadder;
        }
};

class SnakeAndLadder{
    private:
        int sizeOfBoard; // n*n where n - size of board
        vector<vector<identifier>> board;
        map<pair<int,int>,pair<int,int>> snakeOrLadder;

    public:
        void addSnakes(){
            int start_x=(rand() % (this->sizeOfBoard-1 - 0 + 1)) + 0;
            int start_y=(rand() % (this->sizeOfBoard-1 - 0 + 1)) + 0;

            int end_x=(rand() % (this->sizeOfBoard-1 - 0 + 1)) + 0;
            int end_y=(rand() % (this->sizeOfBoard-1 - 0 + 1)) + 0;

            if(!board[start_x][start_y].getIsSnake() and !board[end_x][end_y].getIsLadder()){
                board[start_x][start_y].isSnake=(true);
                board[end_x][end_y].isSnake=(true);
                snakeOrLadder[{start_x,start_y}]={end_x,end_y};
                return;
            }
            else{
                this->addSnakes();
                return;
            }
        }

        void addLadder(){
            int start_x=(rand() % (this->sizeOfBoard-1 - 0 + 1)) + 0;
            int start_y=(rand() % (this->sizeOfBoard-1 - 0 + 1)) + 0;

            int end_x=(rand() % (this->sizeOfBoard-1 - 0 + 1)) + 0;
            int end_y=(rand() % (this->sizeOfBoard-1 - 0 + 1)) + 0;

            if(!board[start_x][start_y].getIsSnake() and !board[end_x][end_y].getIsLadder()){
                board[start_x][start_y].isLadder=(true);
                board[end_x][end_y].isLadder=(true);
                snakeOrLadder[{start_x,start_y}]={end_x,end_y};
                return;
            }
            else{
                this->addLadder();
                return;
            }
        }

        void startPlay(){
            pair<int,int> player1={0,0};
            pair<int,int> player2={0,0};
            
            bool flag=1;
            int choice=1;
            while(1 and choice!=-1){
                //player 1s turn
                cout<<"Player 1s position : "<<player1.first<<" "<<player1.second<<endl;
                cout<<"Player 2s position : "<<player2.first<<" "<<player2.second<<endl;
                if(player1.first==this->sizeOfBoard-1 and player1.second==0){
                    cout<<"Player 1 wins"<<endl;
                    break;
                }
                if(player2.first==this->sizeOfBoard-1 and player2.second==0){
                    cout<<"Player 2 wins"<<endl;
                    break;
                }
                if(flag){
                    cout<<"Player 1's turn"<<endl;
                    int dice=(rand() % (6 - 1 + 1)) + 1;
                    cout<<"Type 1 to roll dice and -1 to exit game "<<endl;
                    cin>>choice;
                    cout<<"Your dice showed :" <<dice<<endl;

                    int temp=(player1.first+dice);
                    if(temp>=this->sizeOfBoard){
                        player1.first=(player1.first+dice)%this->sizeOfBoard;
                        player1.second++;
                    }
                    else{
                        player1.first=temp;
                    }

                    if(board[player1.first][player1.second].getIsSnake()){
                        cout<<"Player 1 is bitten by a snake"<<endl;
                        player1.first=snakeOrLadder[{player1.first,player1.second}].first;
                        player1.second=snakeOrLadder[{player1.first,player1.second}].second;
                    }
                    if(board[player1.first][player1.second].getIsLadder()){
                        cout<<"Player 1 climbed a ladder"<<endl;
                        player1.first=snakeOrLadder[{player1.first,player1.second}].first;
                        player1.second=snakeOrLadder[{player1.first,player1.second}].second;
                    }

                    if(dice==6) flag=1;
                    else flag=0;

                }
                else{
                    cout<<"Player 2's turn"<<endl;
                    int dice=(rand() % (6 - 1 + 1)) + 1;
                    cout<<"Type 1 to roll dice and -1 to exit game "<<endl;
                    cin>>choice;
                    cout<<"Your dice showed :" <<dice<<endl;

                    int temp=player2.first+dice;
                    if(temp>=this->sizeOfBoard){
                        player2.first=(player2.first+dice)%this->sizeOfBoard;
                        player2.second++;
                    }
                    else{
                        player2.first=temp;
                    }

                    if(board[player2.first][player2.second].getIsSnake()){
                        cout<<"Player 2 is bitten by a snake"<<endl;
                        player2.first=snakeOrLadder[{player2.first,player2.second}].first;
                        player2.second=snakeOrLadder[{player2.first,player2.second}].second;
                    }
                    if(board[player2.first][player2.second].getIsLadder()){
                        cout<<"Player 2 climbed a ladder"<<endl;
                        player2.first=snakeOrLadder[{player2.first,player2.second}].first;
                        player2.second=snakeOrLadder[{player2.first,player2.second}].second;
                    }

                    if(dice==6) flag=0;
                    else flag=1;
                }
            }


        }

        SnakeAndLadder(int size){
            this->sizeOfBoard=size;
            this->board.clear();
            this->board.resize(size,vector<identifier>(size,identifier(false,false)));

            cout<<"Snakes and Ladders"<<endl;

            int numOfSnakes=(rand() % (size - 0 + 1)) + 0;
            for(int i=0;i<numOfSnakes;i++){
                this->addSnakes();
            }
            int numOfLadders=(rand() % (size - 0 + 1)) + 0;
            for(int i=0;i<numOfLadders;i++){
                this->addLadder();
            }
            this->startPlay();
        }

};

int main(){
    int size;
    cout<<"Enter size of board : "<<endl;
    cin>>size;
    SnakeAndLadder game(size);
    return 0;
}