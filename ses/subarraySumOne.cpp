#include <bits/stdc++.h>

using namespace std;  

int arr[200010];

int main() {
  int n, x;
  cin >> n >> x;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  int r = 0, sum = arr[0], ans = 0;
  for(int i = 0; i < n; i++) {
    while(r < n and sum < x) {
      r++;
      sum += arr[r];
    }
    ans += sum == x;
    sum -= arr[i];
  }
  cout << ans << endl;
}
