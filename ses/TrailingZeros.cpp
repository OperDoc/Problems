#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for(long long i = 5; n / i > 0; i *= 5) {
    ans += (n / i);
  }
  cout << ans << endl;
}
