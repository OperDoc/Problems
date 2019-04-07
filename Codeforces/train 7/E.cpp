#include <bits/stdc++.h>

using namespace std;


typedef long long z;
#define fo(i, n) for(int i = 0; i != n; i++)
#define fl(i, n) for(int i = 0; i != n.size(); i++)
#define fe(i, n) for(auto &i : n)
#define al(n) n.begin(),n.end()
#define ve vector
#define pb push_back
#define mp make_pair
#define pr pair
#define fs first
#define sc second
#define in cin
#define out cout
#define nl '\n'

long long sumray(int i) {
	return i * (i + 1) / 2;
}

long long sumsq(int i, int j) {
	return (i + 1) * (j + 1) * (i + j) / 2;
}

long long finalsum(int i, int j, int a, int b){
	int ri = a - i - 1;
	int rj = b - j - 1;
	long long cross = sumray(i) + sumray(j) + sumray(ri) + sumray(rj);
	return sumsq(i, j) + sumsq(ri, j) + sumsq(i, rj) + sumsq(ri, rj) - cross;
}

int main() {
	z a, b;
	in >> a >> b;
	
	for(int i = 0; i < a; i++) {

	}
}