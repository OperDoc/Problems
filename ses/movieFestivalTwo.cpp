#include <bits/stdc++.h>

using namespace std;

int ord[200010], start[200010], nd[200010];

int main() {
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    ord[i] = i;
    cin >> start[i] >> nd[i];
  }
  int ans = 0;
  sort(ord, ord + n, [&](int i, int j) {return nd[i] < nd[j] or (nd[i] == nd[j] and start[i] < start[j]);});
  queue<int> q;
  for(int i = 0; i < n; i++) {
    if(k > 0 or q.front() <= start[ord[i]]) {
      if(k == 0) {
	q.pop();
	k++;
      }
      ans++;
      k--;
      q.push(nd[ord[i]]);
    }
  }
  cout << ans << '\n';
}
