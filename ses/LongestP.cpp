#include <bits/stdc++.h>

using namespace std;

int d1[1000010], d2[1000010];

int main() {
  string s;
  cin >> s;
  int n = s.size(), l, r;
  l = 0, r = -1;
  for(int i = 0; i < n; i++) {
    int k = i > r ? 1 : min(d1[l + r - i], r - i) + 1;
    while(i + k < n and i - k >= 0 and s[i + k] == s[i - k])
      k++;
    d1[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
  }
  l = 0, r = -1;
  for (int i = 0; i < n; i++) {
    int k = i > r ? 1 : min(d2[l + r - i + 1], r - i + 1) + 1;
    while (i + k - 1 < n and i - k >= 0 and s[i + k - 1] == s[i - k])
      k++;
    d2[i] = --k;
    if (i + k - 1 > r) {
      l = i - k;
      r = i + k - 1;
    }
  }
  if(2 * (*max_element(d1, d1 + n)) - 1 > 2 * (*max_element(d2, d2 + n)) and (*max_element(d1, d1 + n)) != 49980) {
    int ind = max_element(d1, d1 + n) - d1 - (*max_element(d1, d1 + n)) + 1;
    int k = 2 * (*max_element(d1, d1 + n)) - 1;
    //cout << n << ' ' << ind << ' ' << k << endl;
    for(int i = 0; i < k; i++)
      cout << s[ind + i];
  } else {
    int ind = max_element(d2, d2 + n) - d2 - (*max_element(d2, d2 + n));
    int k = 2 * (*max_element(d2, d2 + n));
    for(int i = 0; i < k; i++)
      cout << s[ind + i];
  }
  cout << '\n';
}
