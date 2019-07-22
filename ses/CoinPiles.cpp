#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;cin >> n;
  while(n--) {
    cin >> a >> b;
    cout << ((abs(a - b) <= min(a, b) and (a + b) % 3 == 0) ? "YES" : "NO") << '\n';
  }
}
