#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
   int n;
   long long cnt = 0, ans = 0;
   string s;
   cin >> n;
   cin >> s;
   vector<long long> dp(n, 0);
   for(int i = n - 1; i >= 0; i--){
      cnt += (s[i] == 'W');
      if(s[i] == 'O'){
         dp[i] = cnt;
      }
   }
   cnt = 0;
   for(int i = n - 1; i >= 0; i--){
      cnt += (s[i] == 'O') * dp[i];
      if(s[i] == 'C'){
         dp[i] = cnt;
      }
   }
   for(int i = 0; i < n; i++){
      if(s[i] == 'C'){
         ans += dp[i];
      }
   }
   cout << ans << endl;
   return 0;
}
