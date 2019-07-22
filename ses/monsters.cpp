 #include <bits/stdc++.h>

using namespace std;

string g[1010];
int da[1010][1010], dm[1010][1010], dans[1010][1010];

int dx = [1, 0, -1, 0];
int dy = [0, 1, 0, -1];

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
	q.push(make_pair(nx, ny));
      }
    }
  }
}

int main() {
  
}
