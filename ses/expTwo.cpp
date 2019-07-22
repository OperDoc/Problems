#include <bits/stdc++.h>

using namespace std;

long long exp(long long a, int b, int md) {
  if(!b)
    return 1;
  if(b & 1)
    return a * exp(a, b - 1, md) % md;
  else 
    return (a = exp(a, b >> 1, md)) * a % md;
}

int main() {
  int n, a, b, c;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    cout << exp(a, exp(b, c, 1e9 + 6), 1e9 + 7) << '\n';
  }
}
