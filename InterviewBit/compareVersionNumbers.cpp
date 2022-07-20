#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int compareVersion(string s1, string s2) {

    int i=0 , j=0;

    if(s1==s2)
    {
        return 0;
    }

   

    while(i<s1.size() || j<s2.size())
    {
        string v1="" , v2="";

        while(i<s1.size() && s1[i]=='0')
        {
            i++;
        }

        while(i<s1.size() && s1[i]!='.')
        {
            v1+=s1[i];
            i++;
        }

           while(j<s2.size() && s2[j]=='0')
        {
            j++;
        }


        while(j<s2.size() && s2[j]!='.')
        {
            v2+=s2[j];
            j++;
        }

        if(v1.size()>v2.size())
        {
            return 1;
        }
        else
        if(v1.size()<v2.size())
        {
            return -1;
        }
        else{
            if(v1>v2)
            {
                return 1;
            }
            else
            {
                if(v1<v2)
                {
                    return -1;
                }
            }
        }
       
        if(i!=s1.size())
        {
            i++;
        }
        if(j!=s2.size())
        {
            j++;
        }
    }

   

    return 0;
}

int main(){
    string a="4444371174137455";
    string b="5.168";
    cout<<compareVersion(a,b)<<endl;
    return 0;
}
