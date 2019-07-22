#include <bits/stdc++.h>

using namespace std;

int dp[100010], arr[100];

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  dp[0] = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 100010; j++) {
      if(dp[j] == i + 1) {
	if(dp[j + arr[i]] != i + 1)
	  dp[j + arr[i]] = i + 2;
	dp[j] = i + 2;
      }
    }
  }
  int ans = 0;
  for(int i = 1; i < 100010; i++)
    if(dp[i] == n + 1)
      ans++;
  cout << ans << endl;
  for(int i = 1; i < 100010; i++)
    if(dp[i] == n + 1)
      cout << i << ' ';
}
