#include <bits/stdc++.h>

using namespace std;

#define cL 2 * i + 1
#define cR 2 * i + 2
#define M (l + r) / 2

int t[800010], arr[200010];
int n;

int st(int i = 0, int l = 0, int r = n) {
  return t[i] = r - l == 1 ? arr[l] : min(st(cL, l, M), st(cR, M, r));
}

int mn(int al, int ar, int i = 0, int l = 0, int r = n) {
  if(ar <= l or r <= al)
    return 1e9;
  if(al <= l and r <= ar)
    return t[i];
  return min(mn(al, ar, cL, l, M), mn(al, ar, cR, M, r));
}

int main() {
  int  q;
  cin >> n >> q;
  for(int i = 0; i < n; i++) 
    cin >> arr[i];
  st();
  for(int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    cout << mn(a - 1, b) << endl;
  }
}
