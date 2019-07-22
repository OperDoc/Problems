#include <bits/stdc++.h>

using namespace std;

string s[1010];
int dp[1010][1010];
const int mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> s[i];
  dp[0][0] = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(s[i][j] != '*') {
	if(i != n - 1)
	  dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
	if(j != n - 1)
	  dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
      }
    }
  }
  cout << (s[n - 1][n - 1] == '*' ? 0 : dp[n - 1][n - 1]) << endl;
}
