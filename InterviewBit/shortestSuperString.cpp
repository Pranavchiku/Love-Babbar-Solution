#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int findOverlappingPair(string str1, string str2, string &str){
    int max=INT_MIN;
    int len1=str1.length();
    int len2=str2.length();

    //check suffix of str1 matches with prefix of str2
    for(int i=1;i<=min(len1,len2);i++){
        //compare last i chars in str1 with first i char in str2
        if(str1.compare(len1-i,i,str2,0,i)==0){
            if(max<i){
                max=i;
                str=str1+str2.substr(i);
            }
        }
    }

    //check prefix of str1 matches with suffix of str2
    for(int i=1;i<=min(len1,len2);i++){
        //compare first i chars in str1 with last i chars in str2
        if(str1.compare(0,i,str2,len2-i,i)==0){
            if(max<i){
                max=i;
                str=str2+str1.substr(i);
            }
        }
    }

    return max;
}

string solve(vector<string> &A) {
    int len=A.size();

    while(len!=1){
        //to store max overlap
        int max=INT_MIN;

        //to store the index of max overlap
        int l,r;

        //involved in max overlap
        string resStr;

        //max overlap
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                string str;

                int res=findOverlappingPair(A[i],A[j],str);

                //check for max overlap
                if(res>max){
                    max=res;
                    l=i;
                    r=j;
                    resStr.assign(str);
                }
            }
        }

        //ignore last element in next cycle
        len--;

        //if no overlap, append arr[len] to arr[0]

        if(max==INT_MIN){
            A[0]+=A[len];
        }
        else{
            //copy resultant string to index l
            A[l].assign(resStr);

            //copy string at last index to index r
            A[r].assign(A[len]);
        }
    }
    return A[0];
}

int main(){
    int n;
    cin>>n;
    vector<string> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<solve(A)<<'\n';
    return 0;
}