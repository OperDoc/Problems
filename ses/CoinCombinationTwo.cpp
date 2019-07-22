#include <bits/stdc++.h>

using namespace std;

int arr[100], dp[1000010];
const int mod = 1e9 + 7;

int main() {
  int n, x;
  cin >> n >> x;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  dp[0] = 1;
  for(int i = 0; i < n; i++)
    for(int j = 1; j < 1000010; j++)
      if(j - arr[i] >= 0)
	dp[j] = (dp[j] + dp[j - arr[i]]) % mod;
  cout << dp[x] << endl;
}
