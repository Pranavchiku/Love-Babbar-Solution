#include<bits/stdc++.h>
// #include "hero.cpp"
using namespace std;
#define ll long long int

class Student{
    private:
        string name;
        int age;
        int height;

    public:
        int getAge(){
            return this->age;
        }
};


class Hero{
    //properties;

    private:
    int health;
    public:
    char level;
    char *name; 
    static int timeToComplete; //independently of hero level


    //simple constructor
    Hero(){
        cout<<"Hero constructor called"<<endl;
        name=new char[100];

    }

    //parameterized constructor
    // Hero(int health){
    //     cout<<"this -> "<<this<<endl;
    //     this->health = health; //current object's address is stored in this->
    // }

    Hero(int health, char level){
        // cout<<"this -> "<<this<<endl;
        this->health = health; //current object's address is stored in this->
        this->level = level;
    }

    //copy constructor

    Hero(Hero& temp){

        cout<<"copy constructor called"<<endl;

        //created a new name array

        char *ch=new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        //assigned the new name array to this object's name
        this->name=ch;
        this->level=temp.level;
        this->health=temp.health;
    }
    void print() {
        cout<<"name: "<<this->name<<endl;
        cout<<"health "<<health<<endl;
        // cout<<level<<endl;
        cout<<"level "<<level<<endl;
    }

    int getHealth(){
        return health;
    }

    char getLevel(){
        return level;
    }

    void setHealth(int h){
        health = h;
    }

    void setLevel(char l){
        level = l;
    }

    void setName(char *n){
        strcpy(name,n);
    }

    static int random(){
        //can only access static members of the class
        return timeToComplete;
    }

    //destructor
    ~Hero(){
        cout<<"Hero destructor called"<<endl;
        // delete[] name;
    }
};


//initalise static variable

int Hero::timeToComplete=10;

int main(){


    Student first;

    
    /*
    //accesed static variable without creating object
    //as it belongs to class
    cout<<"timeToComplete: "<<Hero::timeToComplete<<endl;
    cout<<Hero::random()<<endl;
    */


    //can access but not recommended
    // Hero h1;
    // cout<<"timeToComplete: "<<h1.timeToComplete<<endl;
    /*
    //statically allocated object
    Hero a;

    //dynamically allocated object
    Hero *b = new Hero();

    delete b; //manually called for dynamic object
    */


    /*
    Hero hero1;
    hero1.setHealth(100);
    hero1.setLevel('A');
    char name[7]="Pranav";
    hero1.setName(name);

    hero1.print();

    //use default copy constructor
    Hero hero2(hero1);

    hero2.print();

    hero1.name[0]='G';
    hero1.print();

    hero2.print();


    hero1=hero2;

    hero1.print();
    hero2.print();
    */


    /*
    Hero suresh(70, 'C');

    suresh.print();

    //copy constructor
    Hero ritesh(suresh);

    //above is equal to
    //ritesh.health=suresh.health;
    //ritesh.level=suresh.level;

    ritesh.print();
    */


    /*
    //object created statically
    Hero ramesh=Hero(100,'A');


    //object created dynamically
    Hero *h = new Hero(70,'B');
    cout<<"h -> "<<h<<endl;
    */

    /*
    //dynamically allocation

    Hero* b=new Hero;

    (*b).setHealth(100);
    (*b).setLevel('B');

    cout<<"Health: "<<(*b).getHealth()<<endl;
    cout<<"Level: "<<(*b).getLevel()<<endl;

    cout<<"Health: "<<b->getHealth()<<endl;
    cout<<"Level: "<<b->getLevel()<<endl;


    //static allocation
    //creation of object of type Hero
    Hero ramesh;

    // cout<<"size: "<<sizeof(ramesh)<<endl;

    // //assigning values to properties of object
    // // ramesh.health = 70;

    ramesh.setHealth(70);
    // // ramesh.level = 'A';
    ramesh.setLevel('A');

    cout<<"health is: "<<ramesh.getHealth()<<endl;

    cout<<"level is: "<<ramesh.getLevel()<<endl;

    */

    return 0;
}