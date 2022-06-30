#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int largestPower2(int n){
    int x=0;
    while((1<<x)<=n){
        x++;
    }
    return x-1;
}
int countSetBits(int n)
{
    if(n==0) return 0;
    int x = largestPower2(n);
    
    int btill2x=x*(1<<(x-1));//x*(2^(x-1))
    int msb2xton=n-(1<<x)+1;//n-(2^x)+1
    int rest=n-(1<<x);//n-(2^x)
    int ans=btill2x+msb2xton+countSetBits(rest);
    return ans;

}