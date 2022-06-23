#include <bits/stdc++.h>
using namespace std;
#define ll long long int

#define N 3

// A utility function that returns index of minimum value in arr[]
int getMin(int arr[])
{
    int minInd = 0;
    for (int i=1; i<N; i++)
        if (arr[i] < arr[minInd])
            minInd = i;
    return minInd;
}

// A utility function that returns index of maximum value in arr[]
int getMax(int arr[])
{
    int maxInd = 0;
    for (int i=1; i<N; i++)
        if (arr[i] > arr[maxInd])
            maxInd = i;
    return maxInd;
}

// A utility function to return minimum of 2 values
int minOf2(int x, int y)
{
    return (x<y)? x: y;
}

void minCashFlowRec(int amount[]){
    //find indexes of minimum and maximum values in amount[]
    // amount[mxCredit] indicates the maximum amount to be given
    //                  (or credited) to any person .
    // And amount[mxDebit] indicates the maximum amount to be taken
    //                  (or debited) from any person.
    // So if there is a positive value in amount[], then there must
    // be a negative value

    int mxCredit=getMax(amount);
    int mxDebit=getMin(amount);

    //if both amounts are 0, then all amounts are settled
    if(amount[mxCredit]==0 and amount[mxDebit]==0){
        cout<<"All amounts are settled"<<endl;
        return;
    }

    //find minimum of two amounts
    int min=minOf2(-amount[mxDebit],amount[mxCredit]);

    //update amount array
    amount[mxDebit]+=min;
    amount[mxCredit]-=min;

    cout<<"Person "<<mxDebit<<" pays"<<min<<" to Person "<<mxCredit<<endl;

    //recursively call minCashFlowRec()
    minCashFlowRec(amount);
}

void minCashFlow(int graph[][N]){
    //create an array of amount of size N
    //initialise all values as 0
    int amount[N]={0};

    //calculate the net amount to be paid to person 'p
    //and store it in amount[p]
    //value can be calculated by subtracting debts from credits
    for(int p=0;p<N;p++){
        for(int i=0;i<N;i++){
            //credit-debit
            amount[p]+=graph[i][p]-graph[p][i];

        }
    }
    minCashFlowRec(amount);
}

int main()
{
    // graph[i][j] indicates the amount that person i needs to
    // pay person j
    int graph[N][N] = { {0, 1000, 2000},
                        {0, 0, 5000},
                        {0, 0, 0},};
 
    // Print the solution
    minCashFlow(graph);
    return 0;
}