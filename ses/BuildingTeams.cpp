#include<bits/stdc++.h>

using namespace std;

vector<int> g[100010];
int mark[100010];

bool dfs(int v, int m) {
  mark[v] = m;
  for(auto i : g[v]) {
    if(mark[i] == 0) {
      if(!dfs(i, 3 - m)) {
	return false;
      }
    } else if(mark[i] == mark[v]) {
      return false;
    }
  }
  return true;
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
  for(int i = 0; i < n; i++) {
    if(mark[i] == 0) {
      if(!dfs(i, 1)) {
	cout << "IMPOSSIBLE" << endl;
	return 0;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    cout << mark[i] << ' ';
  }
  cout << endl;
}
