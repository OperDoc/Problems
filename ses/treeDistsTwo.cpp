#include <bits/stdc++.h>

using namespace std;

vector<int> g[200010];
long long sz[200010], res[200010];
int n;

int dfs1(int i = 0, int p = -1) {
  sz[i] = 1;
  for(auto j : g[i])
    if(j != p)
      sz[i] += dfs1(j, i);
  return sz[i];
}

long long dfs2(int i = 0, int p = -1, int d = 0) {
  long long ans = d;
  for(auto j : g[i])
    if(j != p)
      ans += dfs2(j, i, d + 1);
  return ans;
}

void dfs3(int i = 0, int p = -1, long long ans = dfs2()) {
  res[i] = ans;
  for(auto j : g[i]) 
    if(j != p)
      dfs3(j, i, ans + n - 2 * sz[j]);
}

int main(){
  cin >> n;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }
  dfs1();
  dfs3();
  for(int i = 0; i < n; i++)
    cout << res[i] << ' ';
  cout << '\n';
}
