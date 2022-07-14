#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int romanToInt(string A) {
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    
    map<string, int> m;
    for(int i=0;i<13;i++){
        m[sym[i]]=num[i];
    }
    
    int ans=0;
    int i;
    for(i=0;i<A.size()-1;i++){
        string temp="";
        temp+=A[i];
        temp+=A[i+1];
        cout<<temp<<'\n';
        if(m.find(temp)!=m.end()){
            cout<<"here"<<'\n';
            ans+=m[temp];
            i++;
        }
        else{
            temp.pop_back();
            ans+=m[temp];
        }


        
        
    }
    if(i<A.size()) {
        string temp="";
        temp+=A[i];
        ans+=m[temp];
    }
    return ans;
}

int main(){
    string A;
    cin>>A;
    cout<<romanToInt(A);
    return 0;
}
