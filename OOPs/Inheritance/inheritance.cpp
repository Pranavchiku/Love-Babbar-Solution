#include<bits/stdc++.h>
using namespace std;


class Human{
    protected:
        int height;
        int weight;

    private:
        int age;

    public:
        int getAge(){
            return this->age;
        }

        void setWeight(int w){
            this->weight=w;
        }

};

//inheritance

/*
class childClassName: model(public,private,protected) parentClassName{}
*/

//inherited Male class from Human class
class Male: public Human{
    public:
        string color;


        void sleep(){
            cout<<"Male sleeping"<<'\n';
        }

        int getHeight(){
            return this->height;
        }
};
int main(){


    Male m1;
    cout<<m1.getHeight()<<'\n';
    // cout<<m1.height<<'\n';

    /*
    Male object1;

    //though age not in Male
    //but we inherited it from Human class
    cout<<object1.age<<'\n';

    cout<<object1.height<<'\n';

    cout<<object1.weight<<'\n';

    cout<<object1.color<<'\n';

    object1.sleep();

    object1.setWeight(85);

    cout<<object1.weight<<'\n';
    */
    return 0;
}