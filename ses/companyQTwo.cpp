#include <bits/stdc++.h>

using namespace std;

int n;
int tin[200010], t[1600010], d[200010];
vector<int> arr, g[200010];

void dfs(int i = 0, int p = n, int de = 0) {
  d[i] = de;
  tin[i] = arr.size();
  arr.push_back(i);
  for(auto j : g[i]) 
    if(j != p) 
      dfs(j, i, de + 1);
  arr.push_back(p);
}

#define cL 2 * i + 1
#define cR 2 * i + 2
#define M (l + r) / 2

int mn(int i, int j) {
  return d[i] < d[j] ? i : j;
}

int build(int i = 0, int l = 0, int r = arr.size()) {
  return t[i] = r - l == 1 ? arr[l] : mn(build(cL, l, M), build(cR, M, r));
}

int tmn(int al, int ar, int i = 0, int l = 0, int r = arr.size()) {
  if(ar <= l or r <= al)
    return n;
  if(al <= l and r <= ar)
    return t[i];
  return mn(tmn(al, ar, cL, l, M), tmn(al, ar, cR, M, r));
}

int main() {
  int q;
  cin >> n >> q;
  d[n] = 1e9;
  for(int i = 1; i < n; i++) {
    int a;
    cin >> a;
    g[a - 1].push_back(i);
    g[i].push_back(a - 1);
  }
  dfs();
  build();
  for(int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    a = tin[a - 1];
    b = tin[b - 1];
    if(a > b)
      swap(a, b);
    int ans = tmn(a, b + 1);
    cout << ans + 1 << '\n';
  }
}
