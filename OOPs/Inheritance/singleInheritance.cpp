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

class Dog: public Animal{
    public:
        string breed;
};

int main(){
    Dog d1;
    d1.speak();

    cout<<d1.weight<<'\n';
    return 0;
}