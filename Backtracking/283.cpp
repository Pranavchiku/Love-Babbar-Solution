#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isPalindrome(string s, int l, int h){
    while(l<h){
        if(s[l]!=s[h])
            return false;
        l++;
        h--;
    }
    return true;
}
void allPartUtil(vector<vector<string>> &allPart, vector<string> &currPart,int start, int n, string s){
    if(start>=n){
        allPart.push_back(currPart);
        return;
    }

    //pick all possible endpoints for substring
    for(int i=start;i<n;i++){
        if(isPalindrome(s,start,i)){
            currPart.push_back(s.substr(start,i-start+1));
            allPartUtil(allPart,currPart,i+1,n,s);
            currPart.pop_back();
        }
    }
}
vector<vector<string>> allPalindromicPerms(string s) {
    int n=s.length();

    //vector to store all palindromic partitions
    vector<vector<string>> allPart;

    //vector to store curr palindromic partitins
    vector<string> currPart;

    //recursively call the function to generate all palindromic partitions
    //and store in allPart

    allPartUtil(allPart,currPart,0,n,s);

    return allPart;
}