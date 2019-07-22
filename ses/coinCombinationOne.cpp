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
  for(int i = 1; i < 1000010; i++)
    for(int j = 0; j < n; j++)
      if(i - arr[j] >= 0)
	dp[i] = (dp[i] + dp[i - arr[j]]) % mod;
 
  cout << dp[x]  << '\n';
}
