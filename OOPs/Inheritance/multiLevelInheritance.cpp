#include<bits/stdc++.h>
using namespace std;


class Animal{
    public:
        int weight;
        int age;

    public:
        void speak(){
            cout<<"Animal speaking"<<'\n';
        }

};
//dog inherits animal
class Dog: public Animal{
};

//german shepherd inherits dog
class GermanShepherd: public Dog{
    public:
        string color;
};

int main(){
    GermanShepherd g;
    g.speak();
    cout<<g.weight<<'\n';
    return 0;
}