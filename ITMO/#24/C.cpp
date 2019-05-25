#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define fo(i, n) for(int i = 0; i != n; ++i)
#define fe(i, a) for(auto &i : a)
#define al(a) a.begin(),a.end()
#define ve vector
#define pb push_back
#define mp make_pair
#define pr pair
#define fs first
#define sc second
#define in cin
#define out cout 
#define nl '\n'

char mn[1000][1000];
string s;
int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int i, int j, int z = 1) {
  if(mn[i][j] == 'S' and z >= 4) {out << s << nl; mn[i][j] = 'C'; return;}
  mn[i][j] = mn[i][j] == 'S' ? 'S' : 'A';
  for(int k = 0; k < 4; k++) {
    if(0 <= i + dx[k] and i + dx[k] < n and 0 <= j + dy[k] and j + dy[k] < m and (mn[i + dx[k]][j + dy[k]] == '*') or (mn[i + dx[k]][j + dy[k]] == 'S' and z >= 3)) {
      if(k == 0) {
	s += 'D';
      }
      if(k == 1) {
	s += 'R';
      }
      if(k == 2) {
	s += 'U';
      }
      if(k == 3) {
	s += 'L';
      }
      dfs(i + dx[k], j + dy[k], z + 1);
    }
  }
}

int main() {
  //ios_base::sync_with_stdio(0);
  //cin.tie(0), cout.tie(0);
  in >> n >> m;
  for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) in >> mn[i][j];
  for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(mn[i][j] == 'S') dfs(i, j);
}
