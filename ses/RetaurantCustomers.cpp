#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> eves;
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    eves.push_back(make_pair(a, -1));
    eves.push_back(make_pair(b, 1));
  }
  sort(eves.begin(), eves.end());
  int cnt = 0, ans = 0;
  for(auto& i : eves) {
    cnt -= i.second;
    ans = max(ans, cnt);
  }
  cout << ans << endl;
} 
