#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void TOWUtil(int *arr, int n, bool *curr_elements, int no_of_selected_elements, bool* soln, int *min_diff, int sum, int curr_sum, int curr_position){
    if(curr_position==n){
        return;
    }
    if ((n/2 - no_of_selected_elements) > (n - curr_position))
        return;

    // consider the cases when current element is not included in the solution
    TOWUtil(arr, n, curr_elements, no_of_selected_elements,
              soln, min_diff, sum, curr_sum, curr_position+1);

    // consider the cases when current element is included in the solution
    curr_elements[curr_position] = true;
    no_of_selected_elements++;
    curr_sum += arr[curr_position];

    //check if solution is formed
    if(no_of_selected_elements==n/2){
        if(abs(sum/2-curr_sum)<*min_diff){
            *min_diff = abs(sum/2-curr_sum);
            for(int i=0;i<n;i++){
                soln[i] = curr_elements[i];
            }
        }
    }
    else{
        //recurse for the next element

        TOWUtil(arr, n, curr_elements, no_of_selected_elements,
              soln, min_diff, sum, curr_sum, curr_position+1);
    }
    //reset the current element
    curr_elements[curr_position] = false;
}

void tugOfWar(int arr[], int n){
    //boolean array that contains the inclusion and exculsion of the element
    //in current set.
    //excluded number form another set
    bool* curr_elements=new bool[n];

    //inclusion/exclusion array for final solution
    bool *soln=new bool[n];

    int minDiff=INT_MAX;

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        curr_elements[i]=soln[i]=false;
    }

    //find the solution
    TOWUtil(arr, n, curr_elements, 0, soln, &minDiff, sum, 0, 0);
    //print the solution
    cout<<"First subset: "<<'\n';
    for(int i=0;i<n;i++){
        if(soln[i])
            cout<<arr[i]<<" ";
    }
    cout<<'\n';
    cout<<"Second subset: "<<'\n';
    for(int i=0;i<n;i++){
        if(!soln[i])
            cout<<arr[i]<<" ";
    }


}
int main(){
    return 0;
}