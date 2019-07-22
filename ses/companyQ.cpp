#include <bits/stdc++.h>

using namespace std;

int p[20][200010];

int gp(int k, int v) {
  for(int i = 0; i < 20; i++)
    if(k & (1<<i))
      v = p[i][v];
  return v == 0 ? -1 : v;
}

int main() {
  int n, q;
  cin >> n >> q;
  for(int i = 2; i <= n; i++) 
    cin >> p[0][i];
  for(int i = 1; i < 20; i++) 
    for(int j = 1; j <= n; j++) 
      p[i][j] = p[i - 1][p[i - 1][j]];
  for(int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    cout << gp(b, a) << '\n';
  }
}
