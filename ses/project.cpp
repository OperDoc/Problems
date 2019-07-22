#include <bits/stdc++.h>

using namespace std;

struct prj {
  int a, b, c;
};

prj pjs[200010];
pair<int, int> arr[400010];
long long dp[400010];


bool cmp(prj& a, prj& b) {
  return a.b < b.b;
}

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[2 * i].first >> arr[2 * i + 1].first >> pjs[i].c;
    arr[2 * i].second = 2 * i;
    arr[2 * i + 1].second = 2 * i + 1;
  }
  sort(arr, arr + 2 * n);
  int cnt = 1;
  for(int i = 0; i < 2 * n; i++) {
    if(arr[i].second & 1)
      pjs[arr[i].second / 2].b = cnt;
    else
      pjs[arr[i].second / 2].a = cnt;
    if(i != 2 * n - 1)
      cnt += arr[i].first != arr[i + 1].first;
  }
  sort(pjs, pjs + n, cmp);
  int r = 0;
  for(int l = 0; l < n; l++) {
    while(r < pjs[l].b) {
      r++;
      dp[r] = dp[r - 1];
    }
    dp[r] = max(dp[r], dp[pjs[l].a - 1] + pjs[l].c);
  }
  cout << dp[r] << '\n';
}
