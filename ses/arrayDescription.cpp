#include <bits/stdc++.h>

using namespace std;

int arr[100010], dp[100010][110];
const int mod = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> arr[i];

  if(arr[0] == 0) {
    for(int i = 1; i <= m; i++) {
      dp[0][i] = 1;
    }
  } else {
    dp[0][arr[0]] = 1;
  }
  for(int i = 1; i < n; i++) {
    if(arr[i] == 0) {
      for(int j = 1; j <= m; j++) {
	dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
	if(j != 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
	if(j != m) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
      }
    } else {
      dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i]]) % mod;
      if(arr[i] != 1) dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i] - 1]) % mod;
      if(arr[i] != m) dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i] + 1]) % mod;
    }
  }
  int ans = 0;
  for(int i = 1; i <= m; i++)
    ans = (ans + dp[n - 1][i]) % mod;
  cout << ans << endl;
}
