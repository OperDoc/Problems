#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long ans = -1e9 + 7, acc = 0;
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    acc += a;
    ans = max(ans, acc);
    acc = max(0ll, acc);
  }
  cout << ans << endl;
}
