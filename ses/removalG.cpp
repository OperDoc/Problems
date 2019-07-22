#include <bits/stdc++.h>

using namespace std;

long long arr[5010], dp[5010][5010];

long long go(int l, int r, int k) {
  if(l == r)
    return dp[l][l] = k == 1 ? arr[l] : 0;
  if(dp[l][r] != 0)
    return dp[l][r];
  return dp[l][r] = k == 1 ? max(go(l, r - 1, 2) + arr[r], go(l + 1, r, 2) + arr[l]) : min(go(l, r - 1, 1), go(l + 1, r, 1));
}

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  cout << go(0, n - 1, 1) << '\n';
}
