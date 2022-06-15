#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int maxStockOnithDay(vector<int> price, int k){
    int n=price.size();
    vector<pair<int,int>> v(n);
    for(int i=0;i<price.size();i++){
        v[i]={price[i],i+1};
    }

    sort(v.begin(),v.end());
    int count=0;
    for(int i=0;i<price.size();i++){

        if(k>0){
            int number = k/v[i].first;

            if(number>v[i].second){
                count+=v[i].second;
                k-=(v[i].second)*v[i].first;
            }
            else{
                count+=number;
                k-=number*v[i].first;
            }
        }
        else return count;
    }
    return count;


}
int main(){
    int n=3;
    int k=45;
    vector<int> price={7,10,4};
    cout<<maxStockOnithDay(price,k)<<'\n';
    return 0;
}