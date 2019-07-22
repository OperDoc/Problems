#include <bits/stdc++.h>

using namespace std;

int cnt[1000010];

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int a, j = 1;
    cin >> a;
    for(; j * j < a; j++) {
      cnt[j] += a % j == 0;
      cnt[a / j] += a % j == 0;
    }
    cnt[j] += a % j == 0;
  }
  int ans = 1;
  for(int i = 0; i < 1000010; i++)
    ans = max(ans, (cnt[i] >= 2) * i);
  cout << ans << '\n';
}
