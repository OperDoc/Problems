#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, i = 1;
  long long ans = 0;
  const int mod = 1e9 + 7;
  cin >> n;
  for(; i * i < n; i++) {
    long long k = (n - i * i + 1) / i;
    ans = (ans + k * i + (k - 1) * i + k * (k - 1) / 2) % mod;
  }
  if(i * i == n)
    ans = (ans + i) % mod;
  cout << ans << '\n';
}
