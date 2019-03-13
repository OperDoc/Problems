//https://codeforces.com/problemset/problem/1108/D
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[200010][3];

int main(){
   int n;
   cin >> n;
   string s, c = "RGB";
   cin >> s;
   for(int i = 0; i < 3; i++){
      dp[0][i] = s[0] != c[i];
   }
   for(int i = 1; i < n; i++){
      for(int j = 0; j < 3; j++){
         dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + (s[i] != c[j]);
      }
   }
   int ans = 0;
   for(int i = 0; i < 3; i++){
      if(dp[n - 1][ans] > dp[n - 1][i]) ans = i;
   }
   string res;
   res += c[ans];
   cout << dp[n - 1][ans] << endl;
   for(int i = n - 2; i >= 0; i--){
      if(dp[i][(ans + 1) % 3] > dp[i][(ans + 2) % 3]) {
         ans = (ans + 2) % 3;
      } else {
         ans = (ans + 1) % 3;
      }
      res += c[ans];
   }
   reverse(res.begin(), res.end());
   cout << res << '\n';
   return 0;
}
