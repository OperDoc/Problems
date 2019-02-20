//https://codeforces.com/problemset/problem/1060/E
#include <iostream>
#include <vector>

using namespace std;

vector<int> g[300010];
vector<long long> a(300010);
long long ans = 0;

void bfs (int v, int p, int m) {
    a[v]++;
    ans += m;
    for (auto i:g[v]) {
      if (i != p) {
         bfs(i, v, m == 0);
         a[v] += a[i];
      }
   }
}
int main() {
   int n, x, y;
   cin >> n;
   for (int i = 0; i < n - 1; i++) {
      cin >> x >> y;
      g[x - 1].push_back(y - 1);
      g[y - 1].push_back(x - 1);
   }
   bfs(0, -1, 0);
   ans *= (n - ans);
   for (int i = 0; i < n; i++) {
      ans += a[i] * (n - a[i]);
   }
   cout << ans / 2;
}
