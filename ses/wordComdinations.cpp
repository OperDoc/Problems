#include <bits/stdc++.h>

using namespace std;

const int mod1 = 1e9 + 3373, p1 = 37, mod2 = 1e9 + 7, p2 = 53;
long long dp[5010];
long long hashs1[5010], hashs2[5010];
long long pows1[5010], pows2[5010];
vector<pair<pair<int, int>, int>> m[1000000];


void mad(pair<int, int> x) {
  for(auto& i : m[x.first % 1000000]) {
    if(i.first == x) {
      i.second++;
      return;
    }
  }
  m[x.first % 1000000].push_back(make_pair(x, 1));
}

int mge(pair<int, int> x) {
  for(auto& i : m[x.first % 1000000]) {
    if(i.first == x)
      return i.second;
  }
  return 0;
}

int geth1(int l, int r) {
  long long L = l == 0 ? 0 : hashs1[l - 1] * pows1[r - l + 1] % mod1;
  return (hashs1[r] - L + mod1) % mod1;
}


int geth2(int l, int r) {
  long long L = l == 0 ? 0 : hashs2[l - 1] * pows2[r - l + 1] % mod2;
  return (hashs2[r] - L + mod2) % mod2;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  string s, t;
  cin >> s;
  
  for(int i = 0; i < 5010; i++)
    pows1[i] = i == 0 ? 1 : pows1[i - 1] * p1 % mod1;
  
  for(long long i = 0, h = 0; i < s.size(); i++)
    hashs1[i] = h = (h * p1 + s[i] - 'a' + 1) % mod1;
  
  for(int i = 0; i < 5010; i++)
    pows2[i] = i == 0 ? 1 : pows2[i - 1] * p2 % mod2;
  
  for(long long i = 0, h = 0; i < s.size(); i++)
    hashs2[i] = h = (h * p2 + s[i] - 'a' + 1) % mod2;
  
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> t;
    long long h1 = 0;
    for(int i = 0; i < t.size(); i++)
      h1 = (h1 * p1 + t[i] - 'a' + 1) % mod1;
    long long h2 = 0;
    for(int i = 0; i < t.size(); i++)
      h2 = (h2 * p2 + t[i] - 'a' + 1) % mod2;
    mad(make_pair((int)h1, (int)h2));
  }
  dp[0] = 1;
  for(int i = 1; i <= s.size(); i++) {
    for(int j = 0; j <= i; j++) {
      int k = mge(make_pair(geth1(j, i - 1), geth2(j, i - 1)));
      dp[i] = (dp[i] +  k * dp[j]) % mod2;
    }
  }
  cout << dp[s.size()] << '\n';
}
