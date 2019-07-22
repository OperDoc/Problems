#include <bits/stdc++.h>

using namespace std;

int dp[1000010];

int go(int x) {
  if(x == 0)
    return 0;
  if(dp[x] != -1)
    return dp[x]; 
  int c = x, ans = 1e9;
  while(c > 0) {
    if(c % 10 != 0) ans = min(ans, go(x - c % 10) + 1);
    c /= 10;
  }
  return dp[x] = ans;
}

int main() {
  for(int i = 0; i < 1000010; i++)
    dp[i] = -1;
  int x;
  cin >> x;
  cout << go(x) << endl;
}
