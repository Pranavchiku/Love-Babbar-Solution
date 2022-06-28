#include <bits/stdc++.h>
using namespace std;
#define ll long long int


vector<string> wordBreak(int n, vector<string>& dict, string s)
{
    vector<string> result;
    if(s.length()==0)
    {
        result.push_back("");
        return result;
    }
    for(int i=0;i<dict.size();i++){
        if(s.length()>=dict[i].length() and s.substr(0,dict[i].length())==dict[i]){
            vector<string> temp=wordBreak(n,dict,s.substr(dict[i].length(),s.length()-dict[i].length()));
            for(int j=0;j<temp.size();j++){
                if(temp[j]=="")
                    result.push_back(dict[i]);
                else
                    result.push_back(dict[i]+" "+temp[j]);
            }
        }

    }
    return result;
}
int main(){
    return 0;
}