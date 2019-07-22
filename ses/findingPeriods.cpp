#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 1e9 + 7, p = 47, N = 1e6 + 10;
long long hashs[N], pows[N];
 
long long getH(int l, int r) {
  long long L = l == 0 ? 0 : hashs[l - 1] * pows[r - l + 1] % mod;
  return (hashs[r] - L + mod) % mod;
}
 
int main() {
  string s;
  cin >> s;
  for(int i = 0; i < N; i++)
    pows[i] = i == 0 ? 1 : pows[i - 1] * p % mod;
  for(int i = 0; i < s.size(); i++)
    hashs[i] = i == 0 ? s[i] - 'a' + 1 : (hashs[i - 1] * p + s[i] - 'a' + 1) % mod;
  for(int i = s.size() - 2; i >= 0; i--)
    if(getH(0, i) == getH(s.size() - i - 1, s.size() - 1))
      cout << s.size() - i - 1  << ' ';
  cout << s.size() << '\n';
}
