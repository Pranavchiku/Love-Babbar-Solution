#include <bits/stdc++.h>
using namespace std;
#define ll long long int

#define v 4
int countTriangle(int graph[v][v], bool isDirected){
    int count=0;

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            for(int k=0;k<v;k++){
                if(graph[i][j] and graph[j][k] and graph[i][k]){
                    count++;
                }
            }
        }
    }

    return isDirected?count/3:count/6;
}