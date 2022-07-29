#include<bits/stdc++.h>
using namespace std;

class A{
    public:
        void sayHello(){
            cout<<"Hello"<<'\n';
        }

        //function overloaded
        
        //because of adding a parameter, it is overloaded
        void sayHello(string name){
            cout<<"Hello"<<'\n';
        }

        //overloaded previous function
        int sayHello(string name, int n){
            cout<<"Hello"<<'\n';
            return n;
        }

};

class B{
    public:
        int a;
        int b;

    public:
        int add(){
            return a+b;
        }

        //operator overloading
        //operator overloading is used to overload the operators

        //return_type operator() (parameter_list)
        void operator+ (B& obj){
            int val1=this->a;
            int val2=obj.a;
            cout<<"output "<<val2-val1<<'\n';

            // cout<<"output "<<'\n';
        }

        //overloaded brackets
        void operator() (){
            cout<<"I am bracket"<<'\n';
        }
};


class Animal{
    public:
        void speak(){
            cout<<"Animal speaking"<<'\n';
        }
};

class Dog: public Animal{
    public:
        //overloaded speak function
        //i.e. runtime polymorphism

        //this overloaded function will be called 
        //when the object of Dog is used as an Animal object
        void speak(){
            cout<<"Dog barking"<<'\n';
        }
};


int main(){
    Dog d;
    //will print Dog barking
    d.speak();


    /*
    // A a;
    // a.sayHello("pranav");

    B b;
    b.a=10;
    b.b=20;

    B b1;

    b1.a=30;
    b1.b=40;

    b+b1;

    //overloaded bracket
    b();
    */
    return 0;
}