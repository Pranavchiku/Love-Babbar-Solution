#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(int ind, vector<int> &A, vector<vector<int>> &ans, vector<int> &res, int k)
{
    if (k == 0)
    {
        ans.push_back(res);
        return;
    }
    for (int i = ind; i < A.size(); i++)
    {
        if (i != ind && A[i] == A[i - 1])
            continue;
        if (A[i] <= k)
        {
            res.push_back(A[i]);
            solve(i + 1, A, ans, res, k - A[i]);
            res.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int> &A, int B)
{
    vector<vector<int>> ans;
    vector<int> res;
    sort(A.begin(), A.end());
    solve(0, A, ans, res, B);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    int B;
    cin >> B;
    vector<vector<int>> ans = combinationSum(A, B);
    for (auto it : ans)
    {
        for (auto it2 : it)
            cout << it2 << " ";
        cout << '\n';
    }
    return 0;
}
