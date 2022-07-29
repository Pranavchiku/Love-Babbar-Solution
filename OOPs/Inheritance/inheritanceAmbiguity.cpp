#include<bits/stdc++.h>
using namespace std;

class A{
    public:
        void func(){
            cout<<"Inside A::func()"<<'\n';
        }
};

class B{
    public:
        void func(){
            cout<<"Inside B::func()"<<'\n';
        }

};

class C: public A, public B{

};

int main(){
    C c;
    //(::) is scope resolution operator
    c.A::func();
    c.B::func();
    return 0;
}