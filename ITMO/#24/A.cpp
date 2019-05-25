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

char nm[1000][1000];
int cnt[1000];

int main() {
  //ios_base::sync_with_stdio(0);
  //cin.tie(0), cout.tie(0);
  int n, m;
  in >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++) 
      in >> nm[i][j];
  }
  //for(int i = 0; i < n; i++) { 
  //  for(int j = 0; j < m; j++) 
  //    out << nm[i][j];
  //  out << nl;
  // }
  for(int i = 0; i < m; i++) 
    for(int j = 0; j < n; j++) 
      cnt[i] += nm[j][i] == '*';
  int mmin = 0, mx = 0;
  //for(int i = 0; i < m; i++) out << cnt[i] << ' '; 
  for(int i = 0; i < m - 1; i++) mmin = min(mmin, cnt[i] - cnt[i + 1]), mx = max(mx, cnt[i] - cnt[i + 1]);
  out << abs(mmin) << ' ' << mx;
}
