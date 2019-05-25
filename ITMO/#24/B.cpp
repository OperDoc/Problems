#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define fo(i, n) for(int i = 0; i != n; ++i)
#define fe(i, a) for(auto &i : a)
#define al(a) a.begin(),a.end()
#define ve vector
#define pb push_back
#define mp make_pair
#define pr pair
#define fs first
#define sc second
#define in cin
#define out cout 
#define nl '\n'

int cnt[2010];

int main() {
  //ios_base::sync_with_stdio(0);
  //cin.tie(0), cout.tie(0);
  int n;
  in >> n;
  long long ans = 0;
  for(int i = 0; i < 2 * n; i++) in >> cnt[i], ans += cnt[i];
  long long len = ans / n;
  sort(cnt, cnt + 2 * n);
  for(int i = 0; i < n; i++) {
    out << cnt[i] << ' ' << len - cnt[i] << nl;
  }
}
