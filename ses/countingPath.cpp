#include <bits/stdc++.h>

using namespace std;

int n, timer;
int fin[200010], d[200010];
vector<int> euler, g[200010];
int tin[200010], arr[200010], sz[200010], pa[200010];

int dfs(int i = 0, int p = n, int de = 0) {
  pa[i] = p;
  sz[i] = 1;
  tin[i] = timer++;
  d[i] = de;
  fin[i] = euler.size();
  euler.push_back(i);
  for(auto j : g[i]) 
    if(j != p) 
      sz[i] += dfs(j, i, de + 1);
  euler.push_back(p);
  return sz[i];
}

int t[1600010];

#define cL 2 * i + 1
#define cR 2 * i + 2
#define M (l + r) / 2

int mn(int i, int j) {
  return d[i] < d[j] ? i : j;
}

int build(int i = 0, int l = 0, int r = euler.size()) {
  return t[i] = r - l == 1 ? euler[l] : mn(build(cL, l, M), build(cR, M, r));
}

int tmn(int al, int ar, int i = 0, int l = 0, int r = euler.size()) {
  if(ar <= l or r <= al)
    return n;
  if(al <= l and r <= ar)
    return t[i];
  return mn(tmn(al, ar, cL, l, M), tmn(al, ar, cR, M, r));
}

int lsa(int i, int j) {
  if(fin[i] > fin[j])
    swap(i, j);
  return tmn(fin[i], fin[j] + 1);
}

void pad(int i, int j) {
  arr[tin[i]]++;
  arr[tin[j]]++;
  int l = lsa(i, j);
  arr[tin[l]]--;
  arr[tin[pa[l]]]--;
  //cout << i << ' ' << j << ' ' << l << ' ' << pa[l] << endl;
}

int sum(int l, int r) {
  return arr[r] - (l == 0 ? 0 : arr[l - 1]);
}

int main() {
  int q;
  cin >> n >> q;
  d[n] = 1e9;
  tin[n] = n;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }
  dfs();
  build();
  // for(int i = 0; i < n; i++) 
  //  cout << tin[i] << " \n"[i == n - 1];
  for(int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    pad(a - 1, b - 1);
  }
  for(int i = 1; i < n; i++)
    arr[i] += arr[i - 1];
  for(int i = 0; i < n; i++) 
    cout << sum(tin[i], tin[i] + sz[i] - 1) << " \n"[i == n - 1];
}
