 #include <bits/stdc++.h>

using namespace std;

string g[1010];
int da[1010][1010], dm[1010][1010], dans[1010][1010];

int lst[1010][1010];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;

void bfs1() {
  queue<pair<int, int>> q;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(g[i][j] == 'A') {
	da[i][j] = 0;
	q.push(make_pair(i, j));
      }
  
  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(da[nx][ny] == -1 and g[nx][ny] != '#' and (0 <= nx and nx < n) and (0 <= ny and ny  < m)) {
	da[nx][ny] = da[x][y] + 1;
	q.push(make_pair(nx, ny));
      }
    }
  }
}

void bfs2() {
  queue<pair<int, int>> q;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(g[i][j] == 'M') {
	dm[i][j] = 0;
	q.push(make_pair(i, j));
      }
  
  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(dm[nx][ny] == -1 and g[nx][ny] != '#' and (0 <= nx and nx < n) and (0 <= ny and ny  < m)) {
	dm[nx][ny] = dm[x][y] + 1;
	q.push(make_pair(nx, ny));
      }
    }
  }
}

void bfs3() {
  queue<pair<int, int>> q;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(g[i][j] == 'A') { 
	dans[i][j] = 0;
	lst[i][j] = -1;
	q.push(make_pair(i, j));
      }
  
  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(dans[nx][ny] == -1 and g[nx][ny] != '#' and da[nx][ny] < dm[nx][ny] and(0 <= nx and nx < n) and (0 <= ny and ny  < m)) {
	dans[nx][ny] = dans[x][y] + 1;
	lst[nx][ny] = i;
	q.push(make_pair(nx, ny));
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> g[i];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      da[i][j] = dm[i][j] = dans[i][j] = -1;
  bfs1();
  bfs2();
  bfs3();
  pair<int, int> ext = make_pair(-1, -1);
  for(int i = 0; i < n; i++)
    if(dans[i][0] != -1)
      ext = make_pair(i, 0);
  
  for(int i = 0; i < n; i++)
    if(dans[i][m - 1] != -1)
      ext = make_pair(i, m - 1);
  
  for(int i = 0; i < m; i++)
    if(dans[0][i] != -1)
      ext = make_pair(0, i);
  
  for(int i = 0; i < m; i++)
    if(dans[n - 1][i] != -1)
      ext = make_pair(n - 1, i);
  
  /*for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cout << dans[i][j] << " \n"[j == m - 1];

  cout << '\n';
  */
  if(ext == make_pair(-1, -1)) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  //cout << ext.first << ' ' << ext.second << '\n';
  vector<int> ans;
  int k = lst[ext.first][ext.second];
  while(k != -1) {
    ans.push_back(k);
    ext.first -= dx[k];
    ext.second -= dy[k];
    k = lst[ext.first][ext.second];
  }
  string mp = "DRUL";
  reverse(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for(auto i : ans) {
    cout << mp[i];
  }
  cout << '\n';
}
