#include <bits/stdc++.h>
using namespace std;
#define ll long long int

priority_queue<int, vector<int>, greater<int>> minHeap;
priority_queue<int> maxHeap;

void insertHeap(int &x)
{
    if(maxHeap.size()==0 || maxHeap.top()>=x) maxHeap.push(x);
    else minHeap.push(x);
    
    balanceHeaps();
}

//Function to balance heaps.
void balanceHeaps()
{
    if(maxHeap.size()>minHeap.size()+1){
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    else if(minHeap.size()>maxHeap.size()){
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}

//Function to return Median.
double getMedian()
{
    if(maxHeap.size() == minHeap.size())
        return ((double)maxHeap.top() + (double)minHeap.top()) / 2.0;
        
    return (double)maxHeap.top();
}