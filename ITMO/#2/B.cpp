//50 / 100
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int e[101][101], dp[101][101];

int main(){
   int n, m, mod = 1e9 + 7, k;
   cin >> n >> m >> k;
   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         cin >> e[i][j];
      }
   }
   dp[0][0] = 1;
   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         for(int ii = i + 1; ii < n; ii++){
            for(int jj = j + 1; jj < m; jj++){
               if(e[i][j] != e[ii][jj]){
                  dp[ii][jj] += dp[i][j];
                  dp[ii][jj] %= mod;
               }
            }
         }
      }
   }
   cout << dp[n - 1][m - 1];
   return 0;
}s
