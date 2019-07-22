#include <bits/stdc++.h>

using namespace std;

int arr[20], n;

bool mget(int x, int i) {
  return x / (1 << i) % 2;
}

long long check(int x) {
  long long a = 0, b = 0;
  for(int i = 0; i < n; i++) {
    if(mget(x, i)) a += arr[i];
    else b += arr[i];
  }
  return abs(a - b);
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  long long ans = 1e9;
  for(int i = 0; i < (1 << n); i++)
    ans = min(ans, check(i));
  cout << ans << endl;
}
