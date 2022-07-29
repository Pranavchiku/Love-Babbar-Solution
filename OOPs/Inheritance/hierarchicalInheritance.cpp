#include<bits/stdc++.h>
using namespace std;


class A{
    public:
        void func1(){
            cout<<"Inside A::func1()"<<'\n';
        }
};

class B: public A{
    public:
        void func2(){
            cout<<"Inside B::func2()"<<'\n';
        }
};

class C: public A{
    public:
        void func3(){
            cout<<"Inside C::func3()"<<'\n';
        }
};

int main(){
    A a;
    a.func1();

    //inheritance from A
    B b;
    b.func1();
    b.func2();

    //inheritance from A
    C c;
    c.func1();
    c.func3();

    return 0;
}

