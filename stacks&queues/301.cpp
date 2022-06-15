#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class myStack{
    struct Node{
        int data;
        Node *next;
        Node *prev;

        Node (int num){
            this->data=num;
        }
    };

    Node *top=NULL;
    Node *mid=NULL;
    int size=0;

    public:
        void push(int data){
            Node *temp=new Node(data);

            if(size==0){
                top=temp;
                mid=temp;
                size++;
                return;
            }

            top->next=temp;
            temp->prev=top;

            top=top->next;

            if(size%2==1) mid=mid->next;

            size++;

            return;
        }

        int pop(){
            int temp=-1;
            if(size!=0){
                temp=top->data;
                if(size==1){
                    top=NULL;
                    mid=NULL;
                }
                else{
                    top=top->prev;
                    top->next=NULL;
                    if(size%2==0) mid=mid->prev;
                }
                size--;
            }
            return temp;
        }

        int findMiddle(){
            if(size==0) return -1;
            else return mid->data;
        }

        void delMiddle(){
            if(size!=0){
                if(size==1){
                    top=NULL;
                    mid=NULL;
                }
                else if(size==2){
                    mid=mid->prev;
                    top=top->prev;
                    top->next=NULL;
                }
                else{
                    mid->next->prev=mid->prev;
                    mid->prev->next=mid->next;

                    if(size%2==0){
                        mid=mid->prev;
                    }
                    else mid=mid->next;
                }

                size--;
            }
        }
};

int main(){
    myStack s1;
    s1.push(10);
    s1.push(12);

    cout<<s1.findMiddle()<<'\n';
}