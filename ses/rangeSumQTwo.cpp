#include <bits/stdc++.h>

using namespace std;

#define cL 2 * i + 1
#define cR 2 * i + 2
#define M (l + r) / 2

long long t[800010], arr[200010];
int n;

long long st(int i = 0, int l = 0, int r = n) {
  return t[i] = r - l == 1 ? arr[l] : st(cL, l, M) + st(cR, M, r);
}

long long sm(int al, int ar, int i = 0, int l = 0, int r = n) {
  if(ar <= l or r <= al)
    return 0;
  if(al <= l and r <= ar)
    return t[i];
  return sm(al, ar, cL, l, M) + sm(al, ar, cR, M, r);
}

long long ch(int ind, int x, int i = 0, int l = 0, int r = n) {
  if(r - l == 1)
    return t[i] = x;
  if(ind < M) 
    return t[i] = ch(ind, x, cL, l, M) + t[cR];
  return t[i] = t[cL] +  ch(ind, x, cR, M, r);
}

int main() {
  int q;
  cin >> n >> q;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  st();
  for(int i = 0; i < q; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if(a == 1) {
      ch(b - 1, c);
    } else {
      cout << sm(b - 1, c) << endl;
    }
  }
}
