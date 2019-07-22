#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> arr(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i].second >> arr[i].first;
  }
  sort(arr.begin(), arr.end());
  int t = 0, ans = 0;
  for(int  i = 0; i < n; i++) {
    if(t <= arr[i].second) {
      t = arr[i].first;
      ans++;
    }
  }
  cout << ans << endl;
}
