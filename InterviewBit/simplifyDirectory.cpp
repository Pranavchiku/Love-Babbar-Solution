#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void split(string str, char del, vector<string> &v){
    // declaring temp string to store the curr "word" upto del
    string temp = "";
   
    for(int i=0; i<(int)str.size(); i++){
        // If cur char is not del, then append it to the cur "word", otherwise
          // you have completed the word, print it, and start a new word.
         if(str[i] != del){
            temp += str[i];
        }
          else{
            if(temp != ""){
                v.push_back(temp);
                temp = "";
            }
        }
    }
    
    if(temp!=""){
        v.push_back(temp);
    }
}

string simplifyPath(string A) {
    vector<string> v;
    split(A,'/',v);
    
    // for(auto it: v){
    //    cout<<it.size()<<" "<<it<<endl;
    // }
    stack<string> s;
    for(auto it: v){
        if(it!=".." and it!="."){
            s.push(it);
        }
        else if(it==".."){
            if(!s.empty()) s.pop();
        }
    }
    string temp="";
    while(!s.empty()){
        // cout<<s.top()<<'\n';
        // temp.append("/");
        // temp.append(s.top());
        temp="/"+s.top()+temp;
        s.pop();
    }
    
    if(temp=="") temp="/";
    return temp;
}

int main(){
    string A="/home//foo/";
    cout<<simplifyPath(A)<<endl;
    return 0;
}