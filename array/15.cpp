#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int minJumps(int arr[], int n){
    int j = n-1;
    int check[n]={0};
    if(n==1) return 0;
    else{
        for(j=n-1;j>=0;j--){
            if(arr[j]!=0){
                int i=j+1;
                int flag=0;
                while(i<n and i<=arr[j]+j){
                    if(check[i]==1){
                        check[j]=1;
                        flag=1;
                        break;
                    }
                    i++;
                }
                if(i>=n) check[j]=1;
                else if(flag==0) check[j]=0;
            }
            else{
                check[j]=0;
            }
            // cout<<check[j]<<' '<<arr[j]<<'\n';
        }
        if(check[0]==0) return -1;
        else{
            
            int steps[n]={0};
            for(j=n-1;j>=0;j--){
                if(check[j]==1){
                    if(j+arr[j]>=n-1){
                        // cout<<"here"<<'\n';
                        steps[j]=1;
                    }
                    else{
                        int i = j+1;
                        int length = 1;
                        vector<int> v ={};
                        int temp = INT_MAX;
                        while(i<n and i<=arr[j]+j){
                            if(check[i]==1 and steps[i]<temp){
                                temp=steps[i];
                            }
                            i++;
                        }
                        length+=temp;
                        steps[j]=length;
                    }
                }
                else{
                    steps[j]=INT_MAX;
                }
            }
            return steps[0];
        }
    }
}
int minJumps2(int arr[], int n ){
    int j = n-1;
    int steps[n]={0};
    if(n==1) return 0;
    else if(arr[0]==0) return -1;
    else{
        for(j=n-1;j>=0;j--){
            if(j+arr[j]>=n-1) steps[j]=1;
            else{
                if(arr[j]!=0){
                    int i =j+1;
                    int length=1;
                    int temp=INT_MAX;
                    while(i<n and i<=arr[j]+j){
                        if(steps[i]<INT_MAX and steps[i]<temp){
                            temp=steps[i];
                        }
                        i++;
                    }
                    length+=temp;
                    steps[j]=length;
                }
                else steps[j]=INT_MAX;
            }
            // cout<<steps[j]<<' '<<arr[j]<<'\n';
        }
        if(steps[0]<0 or steps[0]>n) return -1;
        else return steps[0];
    }
}

int minJumps3(int arr[], int n){
    int r=0;
    int i=0;
    int c = 0;
    while(i<n and r<=n-1 and i<=r){
        int temp = i+arr[i];
        if(temp>r){
            r=temp;
            c++;
        }
        i++;
    }
    if(i>r) return -1;
    else return c;
}
int main(){
    int n=6;
    int arr[n]={1, 4, 3, 2, 6, 7} ;
    cout<<minJumps3(arr,n)<<'\n';
    return 0;
}