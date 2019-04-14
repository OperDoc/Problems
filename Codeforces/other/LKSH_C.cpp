#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define fo(i, n) for(int i = 0; i != n; ++i)
#define fe(i, a) for(auto &i : a)
#define ff(i, a) for(int i = 0; i != a.size(); ++i)
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

int n, m, k;

char g[50][50];
int sites[50][50];
int ds[17][50][50];
int dist[17][17];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


bool x_ok(int x) {
	return 0 <= x && x < n;
}

bool y_ok(int y) {
	return 0 <= y && y < m;
}

void dfs(int x, int y, int c) {
	sites[x][y] = c;
	fo(i, 4) {
		int nx = x + dx[i];
		int ny = y + dy[i]; 
		bool is = x_ok(nx) && y_ok(ny) && g[nx][ny] == 'X' && sites[nx][ny] == 0;
		if(is) {
			dfs(nx, ny, c);
		}
	}
}
void path(z s) {
	deque< pr<z, z> > q;
	fo(i, n) {
		fo(j, m) {
			if(sites[i][j] != s) {
				ds[s][i][j] = -1;
			} else {
				ds[s][i][j] = 0;
				q.push_back(mp(i, j));
			} 

		}
	}
	while(!q.empty()) {
		auto v = q.front(); q.pop_front();
		fo(i, 4) {
			int nx = v.fs + dx[i];
			int ny = v.sc + dy[i];
			if(x_ok(nx) && y_ok(ny) && g[nx][ny] == 'X' && ds[s][nx][ny] == -1) {
				ds[s][nx][ny] = ds[s][v.fs][v.sc];
				q.push_front(mp(nx, ny));
			}
			if(x_ok(nx) && y_ok(ny) && g[nx][ny] == 'S' && ds[s][nx][ny] == -1) {
				ds[s][nx][ny] = ds[s][v.fs][v.sc] + 1;
				q.push_back(mp(nx, ny));
			}
		}
	}
	fo(i, k + 1) {
		dist[s][i] = 1e9;
	}
	fo(i, n) {
		fo(j, m) {
			dist[s][sites[i][j]] = min(dist[s][sites[i][j]], ds[s][i][j]);
		}
	}
}
bool used[17];
ve<z> ans;
int res;


int dp[131172][17];

int lazeDP(int i, int mask){
	if(dp[i][mask] != 1e9) return dp[i][mask];
	fo(j, k + 1) {
		if(j != i && ((1<<j) & mask)) {
			dp[i][mask] = min(dp[i][mask], lazeDP(j, mask - (1<<j)) + dist[i][j]);
		}
	}
	return dp[i][mask];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	in >> n >> m;
	fo(i, n) {
		fo(j, m) {
			in >> g[i][j];
		}
	}
	int cnt = 0;
	fo(i, n) {
		fo(j, m) {
			if(g[i][j] == 'X' && sites[i][j] == 0) {
				cnt++;
				dfs(i, j, cnt);
			}
		}
	}
	k = cnt;
	for(int i = 1; i <= k; i++) {
		path(i);
	}
	fo(i, k + 1) {
		dist[0][i] = 0;
		dist[i][0] = 0;
	}
	fo(mask, (1<<(k + 1))){
		fo(i, k + 1) {
			dp[mask][i] = 1e9;
		}
	}
	dp[0][0] = 0;
	fo(mask, (1<<(k + 1))) {
		fo(i, k + 1){
			fo(j, k + 1) {
				if(j != i && ((1<<j) & mask)) {
					dp[mask][i] = min(dp[mask][i], dp[mask - (1<<j)][j]+ dist[i][j]);
				}
			}
		}
	}
	out << dp[(1<<(k + 1)) - 1][0] << nl;
}