#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct Item{
    int value;
    int weight;
};

static bool compare(Item a, Item b){
    return (((double)a.value/(double)a.weight)>((double)b.value/(double)b.weight));
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    double maxVal=0;
    int filled=0;

    sort(arr,arr+n,compare);
    for(int i=0;i<n;i++){
        if(arr[i].weight+filled<=W){
            maxVal+=arr[i].value;
            filled+=arr[i].weight;
        }
        else{
            maxVal+=(W-filled)*((double)arr[i].value/(double)arr[i].weight);
            return maxVal;
        }
    }
    return maxVal;
}

int main(){
    int n;cin>>n;
    int w;cin>>w;
    Item arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i].value>>arr[i].weight;
    }

    cout<<fractionalKnapsack(w,arr,n)<<'\n';
}