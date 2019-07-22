#include <bits/stdc++.h>

using namespace std;

#define sz 1000010

int nxt[sz][4];
int dp[sz];
int p[sz];

int main() {
  string s, t = "ACGT";
  cin >> s;
  s += t;
  int n = s.size();
  nxt[n - 1][0] = nxt[n - 1][1] = nxt[n - 1][2] = nxt[n - 1][3] = -1;
  for(int i = n - 2; i >= 0; i--) {
    for(int j = 0; j < 4; j++) {
      nxt[i][j] = nxt[i + 1][j];
    }
    nxt[i][t.find(s[i + 1])] = i + 1;
  }
  for(int i = 0; i < n; i++) {
    dp[i] = 1e9;
    p[i] = -1;
  }
  for(int i = 0; i < 4; i++) {
    dp[s.find(t[i])] = 1;
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 4; j++) {
      if(nxt[i][j] != -1 and dp[nxt[i][j]] > dp[i] + 1) {
	dp[nxt[i][j]] = dp[i] + 1;
	p[nxt[i][j]] = i;
      }
    }
  }
  int ans = min(min(dp[n - 1], dp[n - 2]), min(dp[n - 3], dp[n - 4]));
  int ind;
  for(int i = 1; i <= 4; i++) {
    if(ans == dp[n - i]) ind = n - i;
  }
  string res;
  while(ind != -1) {
    res += s[ind];
    ind = p[ind];
  }
  reverse(res.begin(), res.end());
  cout << res << endl;
}
