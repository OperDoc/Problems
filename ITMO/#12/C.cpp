#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int G[10010], col[10010], len[10010];

int dfs(int v, int c, int ans) {
   ans++;
   col[v] = c;
   if(col[G[v]] == 0) return dfs(G[v], c, ans);
   return ans;
}

int go(int v, int dist){
   for(int i = 0; i < dist; i++) v = G[v];
   return v;
}

int main() {
   int n, k;
   cin >> n >> k;
   for (int i = 1; i <= n; i++){
      cin >> G[i];
   }
   int cnt = 1;
   for(int i = 1; i <= n; i++){
      if(col[i] == 0){
         len[cnt] = dfs(i, cnt, 0);
         cnt++;
      }
   }
   for(int i = 1; i <= n; i++){
      cout << go(i, k % len[col[i]]) << ' ';
   }
   return 0;
}
