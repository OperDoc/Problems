#include <bits/stdc++.h>

using namespace std;

int dp[510][510];

int go(int a, int b) {
  if(a == b)
    return 0;
  if(dp[a][b] != 0)
    return dp[a][b];
  dp[a][b] = 1e9;
  for(int i = 1; i < a; i++)
    dp[a][b] = min(dp[a][b], go(i, b) + go(a - i, b) + 1);
  for(int i = 1; i < b; i++)
    dp[a][b] = min(dp[a][b], go(a, i) + go(a, b - i) + 1);
  return dp[a][b];
		   
}

int main() {
  int n, m;
  cin >> n >> m;
  cout << go(n, m) << endl;
}
