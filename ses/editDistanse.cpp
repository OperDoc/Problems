#include <bits/stdc++.h>

using namespace std;

int dp[5000][5000];
string s, t;

int dist(int n, int m) {
  if(n == 0 or m == 0)
    return n == 0 ? m : n;
  if(dp[n - 1][m - 1] != -1)
    return dp[n - 1][m - 1];
  if(s[n - 1] == t[m - 1])
    return dp[n - 1][m - 1] = dist(n - 1, m - 1);
  else
    return dp[n - 1][m - 1] = 1 + min(min(dist(n - 1, m), dist(n, m - 1)), dist(n - 1, m - 1));
}

int main() {
  for(int i = 0; i < 5000; i++)
    for(int j = 0; j < 5000; j++)
      dp[i][j] = -1;
  cin >> s >> t;
  cout << dist(s.size(), t.size()) << endl;
}
