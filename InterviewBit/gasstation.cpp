#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool solve(const vector<int> &A, const vector<int> &B, int i){
    int j;
    int currP=0;
    for(j=i;j<A.size();j++)
    {
        currP+=A[j];
        int reqP=B[((j+1)%(B.size()))];
        cout<<currP<<" "<<reqP<<endl;
        int deficit=currP-reqP;
        if(deficit<0){
            cout<<"here"<<'\n';
            return false;
        }
        else{
            currP-=reqP;
        }
    }
    for(j=0;j<i;j++){
        currP+=A[j];
        int reqP=B[((j+1)%(B.size()))];
        int deficit=currP-reqP;
        if(deficit<0){
            return false;
        }
        else{
            currP-=reqP;
        }
    }
    return true;
}
int sum(const vector<int> A){
    int ans=0;
    for(auto it: A){
        ans+=it;
    }
    return ans;
}
int canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int sumA=sum(A);
    int sumB=sum(B);
    if(sumA<sumB){
        return -1;
    }
    else{

        int i=0;
        for(i=0;i<A.size();i++){
            if(solve(A,B,i)) return i;
        }
        return -1;
    }
}

int main(){
    vector<int> A={1,2,3,4,5};
    vector<int> B={3,4,5,1,2};
    cout<<canCompleteCircuit(A,B)<<endl;
    return 0;
}