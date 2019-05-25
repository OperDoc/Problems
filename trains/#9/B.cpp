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

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0), cout.tie(0);
  z n, m, ans, cnt;
  in >> n >> m;
  string s;
  in >> s;
  ans = cnt = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == '1') cnt++; else cnt = 0;
    ans = max(ans, cnt);
  }
  for(int i = 0; i < m; i++) {
    int a;
    in >> a;
    if(ans < a) out << "YES" << nl;
    else out << "NO" << nl;
  }
}
