#include <iostream>
#include <vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int N = 10000010;

bool isR(int n) {
	string v = to_string(n);
	for (int i = 0; i <= v.size() / 2; i++) {
		if (v[i] != v[v.size() - 1 - i])  return false;
	}
	return true;
}

int main() {
	long long p, q;
	cin >> p >> q;
	vector<bool> isp(N, true);
   isp[0] = false;
   isp[1] = false;
	for (int i = 2; i < N; i++) {
		if(isp[i]) for (long long j = (long long)i * i; j < N; j += i) isp[j] = false;
	}
	vector<int> cntP(N, 0);
	vector<int> cntR(N, 0);
	for (int i = 1; i < N; i++) {
		cntR[i] = cntR[i - 1] + isR(i);
		cntP[i] = cntP[i - 1] + isp[i];
	}
	for (int i = N - 1; i >= 0; i--) {
		if (q * cntP[i] <= p * cntR[i]) {
			cout << i;
			return 0;
		}
	}
	cout << "Palindromic tree is better than splay tree";
	return 0;
}
