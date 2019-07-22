#include <bits/stdc++.h>

using namespace std;

long long sum[200010];

int main() {
  int n, x;
  cin >> n >> x;
  map<long long, int> m1, m2;
  for(int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    sum[i] = i ? a + sum[i - 1] : a;
    m1[sum[i]]++;
  }
  long long ans = m1[x];
  for(int i = 0; i < n; i++) {
    m2[sum[i]]++;
    ans += m1[x + sum[i]] - m2[x + sum[i]];
  }
  cout << ans << '\n';
}
