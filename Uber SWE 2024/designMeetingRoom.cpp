#include<bits/stdc++.h>
using namespace std;

class Meeting{
    public:
        int startTime;
        int endTime;

        Meeting(){

        }
        Meeting(int start, int end){
            this->startTime=start;
            this->endTime=end;
        }
};

class Rooms{

    private:
        int availableRooms;
        vector<Meeting> rooms;
    
    public:
        Rooms(int rooms){
            this->availableRooms=rooms;
            this->rooms.clear();
            this->rooms.resize(rooms);
            Meeting temp= Meeting(0,0);
            this->rooms.assign(rooms,temp);
        }
        int findAvailableRoom(){
            for(int i=0;i<this->availableRooms;i++){
                if(this->rooms[i].startTime==0 and this->rooms[i].endTime==0){
                    return i;
                }
            }
            return -1;
        }
        void addMeeting(int startTime, int duration){
            int endTime=startTime+duration;
            int index=this->findAvailableRoom();
            if(index==-1){
                cout<<"No available rooms"<<endl;
                return;
            }
            this->rooms[index].startTime=startTime;
            this->rooms[index].endTime=endTime;
        }

        void addRoom(){
            this->availableRooms++;
            Meeting temp= Meeting(0,0);

            this->rooms.push_back(temp);
        }

        void delMeetFromRoom(int index){
            this->rooms[index].startTime=0;
            this->rooms[index].endTime=0;
        }

        void printAllRooms(){
            for(int i=0;i<this->availableRooms;i++){
                cout<<"Room "<<i<<" "<<this->rooms[i].startTime<<" "<<this->rooms[i].endTime<<endl;
            }
        }
};

int main(){
    Rooms r(3);
    r.addMeeting(0,2);
    r.printAllRooms();

    r.addMeeting(3,2);
    r.printAllRooms();

    r.addMeeting(5,2);
    r.printAllRooms();

    r.addMeeting(7,2);
    r.printAllRooms();

    r.delMeetFromRoom(1);
    r.printAllRooms();

    r.addRoom();

    r.printAllRooms();
}