#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> G[100010];
int dp[100010];
bool cmp(int a, int b){
   return dp[a] < dp[b];
}
void dfs(int v) {
   if(dp[v] == 0) {
      dp[v] = G[v].size();
      for(auto i : G[v]) {
         dfs(i);
      }
      sort(G[v].rbegin(), G[v].rend());
      for(int i = 0; i < G[v].size(); i++) {
         dp[v] = max(dp[G[v][i]] + i + 1, dp[v]);
      }
   }
}

int main() {
   cin >> n;
   for(int i = 0, a; i < n - 1; i++){
      cin >> a;
      G[a - 1].push_back(i + 1);
   }
   dfs(0);
   cout << dp[0];
   return 0;
}
