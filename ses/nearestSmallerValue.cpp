#include <bits/stdc++.h>

using namespace std;

#define cL 2 * i + 1
#define cR 2 * i + 2
#define M (l + r) / 2

int t[800010], arr[200010], n;

int build(int i = 0, int l = 0, int r = n) {
  return r - l == 1 ? t[i] = arr[l] : t[i] = min(build(cL, l, M), build(cR, M, r));
}

int Min(int al, int ar, int i = 0, int l = 0, int r = n) {
  if(ar <= l or r <= al) return 1e9 + 7;
  if(al <= l and r <= ar) return t[i];
  return min(Min(al, ar, cL, l, M), Min(al, ar, cR, M, r));
}

int main() {
  cin >> n; n++;
  arr[0] = -1e9 - 6;
  for(int i = 1; i < n; i++)
    cin >> arr[i];
  build();
  for(int i = 1; i < n; i++) {
    int l = 0, r = i;
    while(r - l > 1) {
      //cout << M << ' '  << i << ' ' << Min(M, i) << ' ';
      if(Min(M, i) < arr[i]) l = M;
      else r = M;
    }
    cout << l << ' ';
  }
}
