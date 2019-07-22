#include <bits/stdc++.h>

using namespace std;

const int N = 200 * 1000;

vector<int> g[N];
int tin[N], tout[N];
int arr[N];
long long t[2 * N + 10];
int mtime = 1;
int n;

void dfs(int i = 0, int p = -1) {
  tin[i] = mtime++;
  for(auto j : g[i])
    if(j != p)
      dfs(j, i);
  tout[i] = mtime++;
}

void madd(int x, int k) {
  for(; x <= 2 * n; x += x & -x)
    t[x] += k;
}

long long gsum(int x, long long ans = 0) {
  for(; 0 < x; x -= x & -x)
    ans += t[x];
  return ans;
}

int main() {
  int q;
  cin >> n >> q;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }
  dfs();
  for(int i = 0; i < n; i++) {
    madd(tin[i], arr[i]);
    madd(tout[i], -arr[i]);
  }
  for(int i = 0; i < q; i++) {
    int a;
    cin >> a;
    if(a == 1) {
      int b, c;
      cin >> b >> c;
      b--;
      madd(tin[b], c - arr[b]);
      madd(tout[b], arr[b] - c);
      arr[b] = c;
    } else {
      int b;
      cin >> b;
      b--;
      cout << gsum(tin[b]) << '\n';
    }
  }
}
