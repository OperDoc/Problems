#include <bits/stdc++.h>

using namespace std;

vector<int> g[200010], ng[200010];
int col[200010], u[200010], mt[200010], nn[200010];

void dfs(int v = 0, int c = 1) {
  col[v] = c;
  for(auto i : g[v])
    if(!col[i])
      dfs(i, 3 - c);
}

bool kun(int v, int t) {
  u[v] = t;
  for(auto i : ng[v])
    if((!mt[i]) or (u[mt[i]] != t and kun(mt[i], t)))
      return 1 + (mt[i] = v);
  return 0;
}

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }
  dfs();
  int v1 = 1, v2 = 1;
  for(int i = 0; i < n; i++) {
    nn[i] = col[i] == 1 ? v1 : v2;
    v1 += col[i] == 1;
    v2 += col[i] == 2;
  }
  for(int i = 0; i < n; i++) 
    if(col[i] == 1) 
      for(auto j : g[i]) 
	ng[nn[i]].push_back(nn[j]);
  for(int i = 1; i < v1; i++) {
    kun(i, i);
  }
  int ans = 0;
  for(int i = 1; i < n; i++)
    ans += mt[i] != 0;
  cout << ans << '\n';
}
