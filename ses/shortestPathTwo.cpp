#include <bits/stdc++.h>
 
using namespace std;
 
#define N 510
const long long inf = 1e18;
long long g[N][N];
 
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for(int i0 = 0; i0 < n; i0++)
    for(int i1 = 0; i1 < n; i1++)
      if(i0 != i1)
	g[i0][i1] = inf;
  for(int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a - 1][b - 1] = min(g[a - 1][b - 1], (long long) c);
    g[b - 1][a - 1] = min(g[b - 1][a - 1], (long long) c);
  }
  for(int i0 = 0; i0 < n; i0++) {
    for(int i1 = 0; i1 < n; i1++) {
      for(int i2 = 0; i2 < n; i2++) {
	g[i1][i2] = min(g[i1][i2], g[i1][i0] + g[i0][i2]);
      }
    }
  }
  for(int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    cout << (g[a - 1][b - 1] == inf ? -1 : g[a - 1][b - 1]) << endl;
  }
}
