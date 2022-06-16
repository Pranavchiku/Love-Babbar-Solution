#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int maxStackSum(int stack1[], int stack2[], int stack3[], int n1,int n2, int n3){
    int sum1=0;int sum2=0;int sum3=0;

    for(int i=0;i<n1;i++){
        sum1+=stack1[i];
    }
    for(int i=0;i<n2;i++){
        sum2+=stack2[i];
    }
    for(int i=0;i<n3;i++){
        sum3+=stack3[i];
    }

    int i=0;
    int j=0;
    int k=0;
    while(i<n1 and j<n2 and k<n3){
        int temp=max(max(sum1,sum2),sum3);
        if(sum1==sum2 and sum2==sum3) return sum1;
        if(temp==sum1){
            sum1-=stack1[i];
            i++;
        }
        else if(temp==sum2){
            sum2-=stack2[j];
            j++;
        }
        else if(temp==sum3){
            sum3-=stack3[k];
            k++;
        }
    }
    return -1;
}
int main(){
    int n1=5;
    int stack1[n1]={3,2,1,1,1};
    int n2=3;
    int stack2[n2]={4,3,2};
    int n3=4;
    int stack3[n3]={2,5,4,1};
    cout<<maxStackSum(stack1,stack2,stack3,n1,n2,n3)<<'\n';
}