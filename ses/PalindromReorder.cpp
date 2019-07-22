#include <bits/stdc++.h>

using namespace std;

int cnt[30];

char getChar(int a) {
  return 'A' + a;
}

int main() {
  string s;
  cin >> s;
  for(auto i : s) cnt[i - 'A']++;
  int ind = -1;
  for(int i = 0; i < 30; i++) {
    if(cnt[i] % 2 and ind != -1) {cout << "NO SOLUTION" << endl; return 0;}
    if(cnt[i] % 2) ind = i;
  }
  string ans, revAns;
  for(int i = 0; i < 30; i++)
    for(int j = 0; j < cnt[i] / 2; j++)
      ans.push_back('A' + i);
  revAns = ans;
  reverse(ans.begin(), ans.end());
  cout << ans;
  if(ind != -1) cout << getChar(ind);
  cout << revAns << endl;
}
