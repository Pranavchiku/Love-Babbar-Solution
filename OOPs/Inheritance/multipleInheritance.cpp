#include<bits/stdc++.h>
using namespace std;


class Animal{
    public:
        int weight;
        int age;

    public:
        void bark(){
            cout<<"Animal speaking"<<'\n';
        }

};

class Human{
    public:
        string color;
    public:
        void speak(){
            cout<<"Human speaking"<<'\n';
        }

};

//Multiple Inheritance

class Hybrid: public Animal, public Human{
    public:
        string breed;
};

int main(){
    Hybrid h;
    h.speak();
    h.bark();
    cout<<h.weight<<'\n';
    return 0;
}