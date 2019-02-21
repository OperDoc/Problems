#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N 1010

vector<int> G[N];
bool U[N];
int ans = 0;

void dfs(int v){
   U[v] = true;
   ans++;
   for(auto i : G[v]){
      if(!U[i])dfs(i);
   }
}

int main(){
   int n, m;
   cin >> n >> m;
   for (int i = 0, a, b; i < m; i++) {
      cin >> a >> b;
      G[a - 1].push_back(b - 1);
      G[b - 1].push_back(a - 1);
   }
   dfs(0);
   if(n == m + 1 && ans == n) {
      cout << "yes\n";
   } else {
      cout << "no\n";
   }
   return 0;
}
