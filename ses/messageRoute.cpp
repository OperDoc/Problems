#include <bits/stdc++.h>

using namespace std;

vector<int> g[100010];
int d[100010], p[100010];

void bfs(int s) {
  queue<int> q;
  q.push(s);
  p[s] = -1;
  d[s] = 1;
  while(!q.empty()) {
    int v = q.front();
    q.pop();
    for(auto i : g[v]) {
      if(d[i] == 0 and i != s) {
	p[i] = v;
	d[i] = d[v] + 1;
	q.push(i);
      }
    }
  }
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
  bfs(0);
  if(d[n - 1] == 0) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  cout << d[n - 1] << endl;
  vector<int> ans;
  int cnt = n - 1;
  while(cnt != -1) {
    ans.push_back(cnt);
    cnt = p[cnt];
  }
  reverse(ans.begin(), ans.end());
  for(int i = 0; i < ans.size(); i++)
    cout << ans[i] + 1 << ' ';
  cout << endl;
}
