#include <bits/stdc++.h>

using namespace std;

int arr[200010];

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  sort(arr, arr + n);
  long long ans = 0;
  for(int i = 0; i < n; i++)
    ans += arr[i];
  ans = max(ans,(long long) 2 * arr[n - 1]);
  cout << ans << '\n';
}
