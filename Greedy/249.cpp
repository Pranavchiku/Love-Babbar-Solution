#include <bits/stdc++.h>
using namespace std;
#define ll long long int


vector<int> candyStore(int candies[], int n, int k)
{
    int i=0;
    int j=n-1;

    sort(candies,candies+n);

    int minPrice=candies[i];
    j-=k;
    i++;
    while(j>=i){
        minPrice+=candies[i];
        j-=k;
        i++;
    }

    i=0;
    j=n-1;

    sort(candies,candies+n,greater<int>());

    int maxPrice = candies[i];
    j-=k;
    i++;

    while(j>=i){
        maxPrice+=candies[i];
        j-=k;
        i++;
    }

    return vector<int> {minPrice,maxPrice};
}

int main(){
    int n=5;int k=4;
    int candies[n]={3,2,1,4,5};
    vector<int> out = candyStore(candies,n,k);

    for(auto &it: out) cout<<it<<' ';
    cout<<'\n';
    return 0;
}