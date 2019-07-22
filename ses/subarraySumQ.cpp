#include <bits/stdc++.h>

using namespace std;

struct sect {
  long long mx, sum, l, r;
  sect(){}
  sect(long long a, long long b, long long c, long long d):mx(a), sum(b), l(c), r(d){}
};

sect mer(sect& a, sect& b) {
  return sect(max(a.r + b.l, max(a.mx, b.mx)), a.sum + b.sum, max(a.l, a.sum + b.l), max(b.sum + a.r, b.r));
}

sect t[800010];
int arr[200010];
int n;

#define cL 2 * i + 1
#define cR 2 * i + 2
#define M (l + r) / 2

void build(int i = 0, int l = 0, int r = n) {
  if(r - l == 1) {
    t[i] = sect(arr[l], arr[l], arr[l], arr[l]);
  } else {
    build(cL, l, M);
    build(cR, M, r);
    t[i] = mer(t[cL], t[cR]);
  }
}

void ch(int ind, int x, int i = 0, int l = 0, int r = n) {
  if(r - l == 1) {
    t[i] = sect(x, x, x, x);
    return;
  }
  if(ind < M) {
    ch(ind, x, cL, l, M);
  } else {
    ch(ind, x, cR, M, r);
  }
  t[i] = mer(t[cL], t[cR]);
}

void print(int i = 0, int l = 0, int r = n) {
  if(r - l == 1) {
    cout << t[i].mx << ' ';
    return;
  }
  print(cL, l, M);
  cout << t[i].mx << ' ';
  print(cR, M, r);
}

int main() {
  int m;
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  build();
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    ch(a - 1, b);
    cout << t[0].mx << '\n';
  }
}
