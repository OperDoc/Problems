#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> g[100010];
long long d[100010];

void dfs(int s, int n) {
  fill(d, d + n, 1e18);
  d[s] = 0;
  set<pair<long long, int>> q;
  q.insert(make_pair(0ll, s));
  while(!q.empty()) {
    int v = q.begin()->second;
    q.erase(q.begin());
    for(auto i : g[v]) {
      if(d[v] + i.second < d[i.first]) {
	q.erase(make_pair(d[i.first], i.first));
	d[i.first] = d[v] + i.second;
	q.insert(make_pair(d[i.first], i.first)); 
      }
    }
  }
}  

int main() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a - 1].push_back(make_pair(b - 1, c));
  }
  dfs(0, n);
  for(int i = 0; i < n; i++)
    cout << d[i] << ' ';
  cout << endl;
}
