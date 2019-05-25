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
  int n;
  in >> n;
  string s, t, ans;
  in >> s >> t;
  for(int i = 0; i < n; i++) {
    if(s[i] == '0' and t[i] == '1') ans.push_back('1'); else ans.push_back('0');
  }
  out << ans << nl;
}
