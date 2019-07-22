#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  s += s;
  int n = s.size(), ans = 0;
  for(int i = 0, j, k; i < n / 2;) {
    ans = i;
    for(j = i + 1, k = i; j < n and s[k] <= s[j]; j++)
      if(s[k] < s[j])
	k = i;
      else
	k++;
    while(i <= k)
      i += j - k;
  }
  for(int i = 0; i < n / 2; i++)
    cout << s[ans + i];
  cout << '\n';
}
