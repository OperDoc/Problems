#include <bits/stdc++.h>

using namespace std;

int arr[200010];

int main() {
  int n;
  cin >> n;
  long long sum = 0;
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> arr[i] >> b;
    sum += b;
  }
  sort(arr, arr + n);
  long long ans = 0, cnt = 0;
  for(int i = 0; i < n; i++) {
    cnt += arr[i];
    ans -= cnt;
  }
  ans += sum;
  cout << ans << endl;
}
