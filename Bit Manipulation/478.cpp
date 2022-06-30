
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int findPosition(int N) {
    if((N==0) or ((N&(N-1))!=0)) return -1;
    else{
        int count=0;
        while(N){
            count++;
            N=N>>1;
        }
        return count;
    }
}