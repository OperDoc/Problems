#include <bits/stdc++.h>

using namespace std;

vector<int> g[200010];
int sz[200010];

int dfs(int v = 0) {
  int ans = 1;
  for(auto i : g[v])
    ans += dfs(i);
  return sz[v] = ans;
}

int main() {
  int n;
  cin >> n;
  for(int i = 1; i < n; i++) {
    int a;
    cin >> a;
    g[a - 1].push_back(i);
  }
  dfs();
  for(int i = 0; i < n; i++)
    cout << sz[i] - 1 << ' ';
  cout << '\n';
}
