#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int countSetBits(int n)
{
    int x = log2(n);
    int count=0;
    count+=((1<<(x-1))*(x)); //x*2^(x-1)

    count+=(n-(1<<x)+1); //(n-2^x+1)

    int left=(n-(1<<x)); //(n-2^x)

    int ans=count+countSetBits(left);
    return ans;
}