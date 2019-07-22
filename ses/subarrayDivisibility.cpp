#include <bits/stdc++.h>

using namespace std;

int sum[200010], m[200010];
int n;

int f(int x) {
  return (x % n + n) % n;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    sum[i] = i ? f(sum[i - 1] + a) : f(a);
    m[sum[i]]++;
  }
  long long ans = m[0];
  for(int i = 0; i < n; i++) {
    ans += (long long)--m[sum[i]];
  }
  cout << ans << '\n';
  
}
