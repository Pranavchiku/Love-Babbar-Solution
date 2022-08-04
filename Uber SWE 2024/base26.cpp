#include<bits/stdc++.h>
using namespace std;
void convertBase(string N)
{
    // 128 bit integer to store
    // the decimal conversion
    int decimal = 0;
 
    // Loop to iterate N
    for (int i = 0; i < N.length(); i++) {
        // Binary to decimal
        decimal = decimal * 2 + (N[i] - '0');
    }
 
    // Stores the base 6 int
    vector<int> ans;
    while (decimal > 0) {

        ans.push_back(decimal % 6);
        decimal = decimal / 6;
    }
 
    // Print Answer
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
}
 
// Driver Code
int main()
{
    string N = "01111";
    convertBase(N);
 
    return 0;
}
 