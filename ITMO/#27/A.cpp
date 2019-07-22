#include <bits/stdc++.h>

using namespace std;

bool arr[150][150];

int main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  for(int i = 0; i < n; i++) arr[0][i] = s[i] - '0';
  for(int i = 1; i <= m; i++) {
    string s;
    cin >> s;
    if(s[0] == 'q') {
      int l, r, ans = 0;
      cin >> l >> r;
      l--;
      r--;
      r--;
      for(int j = 0; j < i; j++) {
	int cnt = 0;
	for(int k = l; k <= r; k++) {
	  cnt +=  arr[j][k];
	}
	ans += cnt == (r - l + 1);
      }
      cout << ans << endl;
      for(int j = 0; j < n; j++) arr[i][j] = arr[i - 1][j];
    } else {
      int k;
      cin >> k;
      k--;
      for(int j = 0; j < n; j++) arr[i][j] = arr[i - 1][j];
      arr[i][k] = !arr[i][k];
    }
  }
}
