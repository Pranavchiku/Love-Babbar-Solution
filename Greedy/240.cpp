#include <bits/stdc++.h>
using namespace std;
#define ll long long int


struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

static bool compare(Job a, Job b){
    return a.profit>b.profit;
}
vector<int> JobScheduling(Job arr[], int n) 
{ 
   int time=0;
   int prof=0;

   int maxDead=INT_MIN;
   sort(arr,arr+n,compare);

    bool done[n]={0};
    // for(int i=0;i<n;i++){
    //     cout<<arr[i].dead<<' '<<arr[i].profit<<'\n';
    // }
   for(int i=0;i<n;i++){

        for(int j=min(n,arr[i].dead-1);j>=0;j--){
            if(done[j]==false){
                time++;
                prof+=arr[i].profit;
                done[j]=true;
                break;
            }
        }
    // cout<<time<<'\n';
   }
   return vector<int> {time,prof};
} 
int main(){
    int n;
    cin>>n;
    Job arr[n];

    for(int i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        arr[i].id=x;
        arr[i].dead=y;
        arr[i].profit=z;

    }

    vector<int> out = JobScheduling(arr,n);

    for(auto& it: out){
        cout<<it<<'\n';
    }
    

    return 0;
}