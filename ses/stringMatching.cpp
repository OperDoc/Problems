#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, p = 47, N = 1e6 + 10;
long long hashs[N], pows[N], hasht[N];

long long getH(int l, int r) {
  long long L = l == 0 ? 0 : hashs[l - 1] * pows[r - l + 1] % mod;
  return (hashs[r] - L + mod) % mod;
}

int main() {
  string s, t;
  cin >> s >> t;
  for(int i = 0; i < N; i++)
    pows[i] = i == 0 ? 1 : pows[i - 1] * p % mod;
  for(int i = 0; i < s.size(); i++)
    hashs[i] = i == 0 ? s[i] - 'a' + 1 : (hashs[i - 1] * p + s[i] - 'a' + 1) % mod;
  for(int i = 0; i < t.size(); i++)
    hasht[i] = i == 0 ? t[i] - 'a' + 1 : (hasht[i - 1] * p + t[i] - 'a' + 1) % mod;
  int ans = 0;
  for(int i = 0; i + t.size() < s.size() + 1; i++)
    ans += getH(i, i + t.size() - 1) == hasht[t.size() - 1];
  cout << ans << '\n';
}
