#include <bits/stdc++.h>

using namespace std;

int arr[200010];
pair<pair<int, int>, int> qs[200010];
int used[200010];
int ans[200010];
const int k = 450;

int cmp(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
  return a.first.first / k != b.first.first / k ? a.first.first < b.first.first : a.first.second < b.first.second; 
}

bool madd(int x) {
  return (used[x] += 1) == 1;
}

bool mdel(int x) {
  return (used[x] -= 1) == 0;
}

int main() {
  int n, q;
  cin >> n >> q;
  for(int i = 1; i <= n; i++) 
    cin >> arr[i];
  map<int, int> m;
  int kk = 0;
  for(int i = 1; i <= n; i++) {
    if(!m[arr[i]])
      m[arr[i]] = ++kk;
    arr[i] = m[arr[i]];
  }

  for(int i = 0; i < q; i++) {
    cin >> qs[i].first.first >> qs[i].first.second;
    qs[i].second = i;
  }
  sort(qs, qs + q, cmp);
  int l = 1, r = 0;
  int res = 0;
  used[0] = -1;
  for(int i = 0; i < q; i++) {
    while(l > qs[i].first.first) {
      res += madd(arr[l - 1]);
      l--;
    }
    while(r < qs[i].first.second) {
      res += madd(arr[r + 1]);
      r++;
    } 
    while(l < qs[i].first.first)  {
      res -= mdel(arr[l]);
      l++;
    } 
    while(r > qs[i].first.second) {
      res -= mdel(arr[r]);
      r--;
    }
    ans[qs[i].second] = res;
  }
  for(int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }
}
