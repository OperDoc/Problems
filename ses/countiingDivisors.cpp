#include <bits/stdc++.h>

using namespace std;

int dvs(int x, int i = 1) {
  int ans = 0;
  for(; i * i < x; i++)
    ans += 2 * (x % i == 0);
  return ans + (i * i == x);
}

int main() {
  int n, a;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a;
    cout << dvs(a) << '\n';
  }
}
