#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int findUnique(int arr[], int n){
    //every element is present twice except one element
    int xor_res = 0;
    for(int i=0;i<n;i++){
        xor_res ^= arr[i];
    }
    return xor_res;
}


vector<int> findUnique2(int arr[], int n){
    //every element is present twice except two element

    int xor_res = 0;
    for(int i=0;i<n;i++){
        xor_res ^= arr[i];
    }
    int tempxor=xor_res;
    //find the rightmost set bit
    int setbit=0;
    int pos=0;
    while(setbit!=1){
        setbit=xor_res&1;
        pos++;
        xor_res=xor_res>>1;
    }

    //loop through all elements of array
    //and check if at posth position contains set bit
    int newxor=0;
    for(int i=0;i<n;i++){
        if(arr[i]&(1<<(pos-1))){
            newxor ^= arr[i];
        }
    }

    //newxor is one unique no.
    //second unique number is tempxor^newxor

    return {newxor,tempxor^newxor};

} 

int findUnique3(int arr[], int n){
    //every element present thrice, except one
    int result=0;
    for(int i=0;i<64;i++){
        int count=0;
        for(int j=0;j<n;j++){
            //check if bit is set

            if(arr[j]&(1<<i)){
                count++;
            }
        }
        //if count%3!=0, then it is unique no.
        if(count%3!=0){
            //set that bit as 1
            result = result | (1<<i);
        }
    }
    return result;
}
void subsets(int arr[], int n){
    //(i<<n) is 2^n
    for(int i=0;i<(i<<n);i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
    }
}

int countSetBits(int n){
    int count=0;
    while(n){
        count++;
        n&=(n-1);
    }
    return count;
}
int checkPow2(int n){
    if(n==0) return false;
    return !(n&(n-1));
}
int updateBit(int n, int pos, int val){
    int mask = 1 << pos;
    if(val == 1){
        return n | mask;
    }
    else{
        return n & ~mask;
    } 
}

int clearBit(int n, int pos){
    return n & ~(1<<pos);
}
int setBit(int n, int pos){
    return n | (1<<pos);
}

int getBit(int n, int pos){
    //Ex: n=5, pos=2, bin 5= 0101 -> ans must be yes
    //left shift 1 by 2 i.e. 1<<2 = 0100, here we can see
    //that we got 1 in the 2nd position
    //now and this with 5 i.e 0100 & 0101,
    //we get 0100!=0 so we return 1
    //else return 0

    
    //left shit 1 till post
    //this will lead to form 1 at pos position
    int mask = 1 << pos;
    //now take n and and with mask
    int n_and_mask = n & mask;
    if(n_and_mask == 0){
        return 0;
    }
    else{
        return 1;
    }
}
int main(){
    return 0;
}