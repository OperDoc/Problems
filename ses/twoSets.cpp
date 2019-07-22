#include <bits/stdc++.h>

using namespace std;

int dp[510][64010];
const int mod = 1e9 + 7;

long long pw(long long a, int n) {
  if(n & 1)
    return n == 1 ? a : a * pw(a, n - 1) % mod;
  return (a = pw(a, n / 2)) * a % mod;
}


int main() {
  int n;
  cin >> n;
  if(n * (n + 1) % 4) {
    cout << 0 << '\n';
    return 0;
  }
  int nn = n * (n + 1) / 4;
  dp[0][0] = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= nn; j++) {
      dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
      if(j + i + 1 <= nn)
	dp[i + 1][j + i + 1] = (dp[i + 1][j + i + 1] + dp[i][j]) % mod;
    }
  }
  cout << pw(2ll, mod - 2) * dp[n][nn] % mod  << '\n';
}
