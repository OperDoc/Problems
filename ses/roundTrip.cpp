
#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> g[100010];
int d[100010], p[100010];
vector<int> path;
 
int dfs(int v, int pa, int de) {
  d[v] = de;
  p[v] = pa;
  int x;
  for(auto i : g[v]) {
     if(d[i] != 0 and d[v] - d[i] > 1) {
      cout << d[v] - d[i] + 2 << endl;
      p[i] = v;
      return i;
    }
    if(d[i] == 0 and (x = dfs(i, v, de + 1)) != 0) { 
      return x;
    }
  }
  return 0;
}
 
void show_path(int x) {
  int cnt = x;
  cout << cnt << ' ';
  cnt = p[cnt];
  while(cnt != x) {
    cout << cnt << ' ';
    cnt = p[cnt];
    if(cnt == 0) break;
  }
  cout << cnt << endl;
}
 
int main() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for(int i = 1; i <= n; i++) {
    int x;
    if(d[i] == 0 and (x = dfs(i, 0, 1)) != 0) {
      show_path(x);
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;
}
