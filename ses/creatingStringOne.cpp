#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  vector<string> ans;
  ans.push_back(s);
  while(next_permutation(s.begin(), s.end())) ans.push_back(s);
  cout << ans.size() << '\n';
  for(auto& i : ans) cout << i << '\n';
}
