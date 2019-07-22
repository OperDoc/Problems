#include <bits/stdc++.h>

using namespace std;

int arr[1010][1010], sum[1010][1010];

int main() {
  int n, q;
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      char a;
      cin >> a;
      arr[i][j] = a == '*';
    }
  }
  for(int i = 0; i < n; i++){
    sum[0][i] = i == 0 ? arr[0][0] : arr[0][i] + sum[0][i - 1];
    sum[i][0] = i == 0 ? arr[0][0] : arr[i][0] + sum[i - 1][0];
  }
  for(int i = 1; i < n; i++)
    for(int j = 1; j < n; j++)
      sum[i][j] = arr[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
  for(int i = 0; i < q; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--; b--; c--; d--;
    int ans = sum[c][d];
    if(b != 0) ans -= sum[c][b - 1];
    if(a != 0) ans -= sum[a - 1][d];
    if(a != 0 and b != 0) ans += sum[a - 1][b - 1];
    cout << ans << endl; 
  }
}
