#include <bits/stdc++.h>

using namespace std;

int xr[200010];

int main() {
  int n, q;
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> xr[i];
    xr[i] ^= (i == 0 ? 0 : xr[i - 1]); 
  }
  for(int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    cout << (xr[b - 1] ^ (a == 1 ? 0 : xr[a - 2])) << '\n'; 
  }
}
