#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void multiply(vector<int> &A, int &si, int ei, int num) {
	int carry = 0;
	while (si <= ei) {
		int mul = A[ei] * num + carry;
		carry = mul / 10;
		A[ei] = mul % 10;
		ei--;
	}
	while (carry) {
		A[--si] = carry % 10;
		carry = carry / 10;
	}
}

vector<int> factorial(int n) {
	int len = 10000;
	vector<int> A(len, 0);
	A[len - 1] = 1;
	int si = len - 1;
	for (int i = 2; i <= n; i++) {
		multiply(A, si, len - 1, i);
	}
	vector<int> result;
	for (int i = si; i < len; i++) {
		result.push_back(A[i]);
	}
	return result;
}

int main(){
    int n=897;
    vector<int> out = factorial(n);
    for(auto& it: out) cout<<it<<' ';
    cout<<'\n';
    return 0;
}