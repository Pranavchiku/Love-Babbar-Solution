#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

static bool comparator(Interval i1, Interval i2) {
    return i1.start < i2.start;
}

vector<Interval> merge(int n, vector<Interval> v){
    sort(v.begin(), v.end(), comparator);
    vector<Interval> result={v[0]};
    int end=1;
    for(int i=1;i<n;i++){
        if(v[i].start>result[end-1].end){
            result.push_back(v[i]);
            end++;
        }
        else{
            result[end-1].end=max(result[end-1].end,v[i].end);
        }
    }    

    return result;

}