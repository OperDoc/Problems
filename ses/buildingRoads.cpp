#include <bits/stdc++.h>

using namespace std;

vector<int> g[100010];
int used[100010];

bool dfs(int v) {
  used[v] = 1;
  for(auto i : g[v])
    if(!used[i])
      dfs(i);
}

int main() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }
  vector<int> ans;
  for(int i = 0; i < n; i++) {
    if(!used[i]) {
      ans.push_back(i);
      dfs(i);
    }
  }
  cout << ans.size() - 1 << endl;
  for(int i = 0; i < ans.size() - 1; i++)
    cout << ans[i] + 1 << ' ' << ans[i + 1] + 1 << endl;
}
