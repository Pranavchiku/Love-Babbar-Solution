#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void SortedStack :: sort()
{
   stack<int> st;

   stack<int> temp;

   while(!s.empty()){
       st.push(s.top());
       s.pop();
   }

   while(!st.empty()){
       if(s.empty()){
           s.push(st.top());
           st.pop();
       }
       else{
           int elem=st.top();
           st.pop();
           while(!s.empty() and s.top()>elem){
               temp.push(s.top());
               s.pop();
           }

           s.push(elem);
           while(!temp.empty()){
               s.push(temp.top());
               temp.pop();
           }
       }
   }

}
int main(){
    
    
    return 0;
}