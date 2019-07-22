#include <bits/stdc++.h>

using namespace std;

#define mod 998244353

long long pw[1000010];

int main() {
  int n, k;
  cin >> n >> k;
  long long m0 = n / 2, m1 = (n - 1) / 2;
  for(int i = 0; i <= k; i++) pw[i] = i == 0 ? 1 : pw[i - 1] * m0 % mod;
  long long ans = pw[k];
  for(int i = k - 1; i >= 0; i--) ans = (ans + m1 * pw[i]) % mod;
  cout << ans << '\n';
}
