#include <bits/stdc++.h>
using namespace std;
#define ll long long int


typedef struct Node{
    int s;
    int e;
}Node;

static bool compare(Node a, Node b){
    return a.e<b.e;
}

int maxMeetings(int start[], int end[], int n)
{
    Node arr[n];
    for(int i=0;i<n;i++){
        arr[i].s=start[i];
        arr[i].e=end[i];
    }

    sort(arr,arr+n,compare);

    // for(int i=0;i<n;i++){
    //     cout<<arr[i].s<<' '<<arr[i].e<<'\n';
    // }

    int lastEnd=arr[0].e;
    int number=1;
    for(int i=1;i<n;i++){
        if(arr[i].s>lastEnd){
            number++;
            lastEnd=arr[i].e;
        }
    }
    return number;
}
int main(){
    int n = 6;
    int start[n]={1,3,0,5,8,5};
    int end[n]={2,4,6,7,9,9};

    cout<<maxMeetings(start,end,n)<<'\n';
    return 0;
}