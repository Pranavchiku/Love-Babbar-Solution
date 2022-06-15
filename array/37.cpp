#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void threeWayPartition(int arr[], int n,
                int lowVal, int highVal)
{
    // Initialize ext available positions for
    // smaller (than range) and greater elements
    int start = 0, end = n-1;
 
    // Traverse elements from left
    for (int i=0; i<=end;)
    {
        // If current element is smaller than
        // range, put it on next available smaller
        // position.
        if (arr[i] < lowVal)
        {
          //if i and start are same in that case we can't swap
          //swap only if i is greater than start
          if(i==start)
          {
            start++;
            i++;
          }
          else{
            // swap(arr[i++], arr[start++]);
            int temp=arr[i];
            arr[i]=arr[start];
            arr[start]=temp;
            i++;start++;
          }
        }
 
        // If current element is greater than
        // range, put it on next available greater
        // position.
        else if (arr[i] > highVal){
            // swap(arr[i], arr[end--]);
            int temp=arr[i];
            arr[i]=arr[end];
            arr[end]=temp;
            end--;
        }
 
        else
            i++;
    }
}

int main(){
    return 0;
}