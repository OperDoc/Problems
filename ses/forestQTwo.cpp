#include <bits/stdc++.h>

using namespace std;

int tree[1010][1010];
int arr[1010][1010];
int n, m;

int gsum(int x, int y, int ans = 0) {
  for(int i = x; i > 0; i -= i & -i)
   for(int j = y; j > 0; j -= j & -j)
    ans += tree[i][j]; 
  return ans;
}

void madd(int x, int y, int k) {
  for(int i = x; i <= n; i += i & -i)
    for(int j = y; j <= n; j += j & -j)
      tree[i][j] += k;
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      //cout << 1 << endl;
      char a;
      cin >> a;
      arr[i + 1][j + 1] = a == '*';
      madd(i + 1, j + 1, arr[i + 1][j + 1]);
    }
  }
  for(int i = 0; i < m; i++) {
    int a;
    cin >> a;
    if(a == 1) {
      int b, c;
      cin >> b >> c;
      madd(b, c, -2 * arr[b][c] + 1);
      arr[b][c] = 1 - arr[b][c];
    } else {
      int b, c, d, e;
      cin >> b >> c >> d >> e;
      int ans = gsum(d, e);
      if((b - 1) * e > 0)
        ans -= gsum(b - 1, e);
      if((c - 1) * d > 0)
        ans -= gsum(d, c - 1);
      if((b - 1) * (c - 1) > 0)
        ans += gsum(b - 1, c - 1);
      cout << ans << '\n';
    }
  }

}











