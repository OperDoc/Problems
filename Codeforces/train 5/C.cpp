#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define fo(i, n) for(int i = 0; i < n; i++)
#define fe(i, a) for(auto &i : a)
#define ff(i, a) for(int i = 0; i < a.size(); i++)
#define mp make_pair
#define pb push_back
#define al(a) a.begin(),a.end() 
#define pr pair
#define ve vector
#define fs first
#define sc second
#define in cin
#define out cout 
#define nl '\n'

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    z n, a;
    in >> n;
    ve<z> ns(n), ord(n);
    ve<ve<z>> cnt(n);
    ve<pr<z, z>> ans(n);
    fo(i, n) {in >> ns[i]; ns[i]--; cnt[ns[i]].pb(i);}
    iota(al(ord), 0);
    sort(al(ord), [&](z i, z j){return cnt[i].size() < cnt[j].size();});
    reverse(al(ord));
    z c = 0;
    fo(i, n) {
        fe(j, cnt[ord[i]]) {
            ans[j] = mp(i, c);
            c++;
        }
    }
    fo(i, n) out << ans[i].fs + 1 << ' ' << ans[i].sc + 1 << nl;

}