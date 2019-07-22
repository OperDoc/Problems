#include <bits/stdc++.h>

using namespace std;

#define cL 2 * i + 1
#define cR 2 * i + 2
#define M (l + r) / 2

long long t[800010], c[800010], arr[200010];
int n;

long long st(int i = 0, int l = 0, int r = n) {
  return t[i] = r - l == 1 ? arr[l] : min(st(cL, l, M), st(cR, M, r));  
}

void push(int i) {
  c[cR] += c[i];
  c[cL] += c[i];
  c[i] = 0;
}

long long mn(int al, int ar, int i = 0, int l = 0, int r = n) {
  if(ar <= l or r <= al)
    return 1e18;
  if(al <= l and r <= ar)
    return t[i] + c[i];
  push(i);
  long long ans = min(mn(al, ar, cL, l, M), mn(al, ar, cR, M, r));
  t[i] = min(t[cL] + c[cL], t[cR] + c[cR]);
  return ans;
}

void upd(int al, int ar, int x, int i = 0, int l = 0, int r = n) {
  if(ar <= l or r <= al)
    return;
  if(al <= l and r <= ar)
    return void(c[i] += x);
  push(i);
  upd(al, ar, x, cL, l, M);
  upd(al, ar, x, cR, M, r);
  t[i] = min(t[cL] + c[cL], t[cR] + c[cR]);
}

int main() {
  int q;
  cin >> n >> q;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  st();
  for(int i = 0; i < q; i++) {
    int a;
    cin >> a;
      if(a == 1) {
	int b, c, d;
	cin >> b >> c >> d;
	upd(b - 1, c, d);
      } else {
	int b;
	cin >> b;
	cout << mn(b - 1, b) << endl;
      }
  }
}
