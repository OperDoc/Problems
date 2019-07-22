#include <bits/stdc++.h>

using namespace std;

int arr[200010];

long long pro(long long t, int n) {
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    ans += t / arr[i];
  }
  return ans;
}

int main() {
  long long n, x;
  cin >> n >> x;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  long long v = *max_element(arr, arr + n);
  long long l = 0, r = max(100000ll, (x * v + n - 1) / (n));
  while(r - l > 1) {
    long long m = (l + r) / 2;
    if(pro(m, n) >= x) r = m;
    else l = m;
  }
  cout << r << endl;
}
