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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    z n, h;
    in >> n >> h;
    ve<z> g(n), f(n), ord(n), Max(n);
    fo(i, n) in >> g[i] >> f[i];
    iota(al(ord), 0);
    sort(al(ord), [&](int i, int j){return f[i] < f[j];});
    Max[ord[n - 1]] = g[ord[n - 1]];
    for(z i = n - 2; i >= 0; i--) Max[ord[i]] = max(g[ord[i]], Max[ord[i + 1]]);
    ve<pr<z, z>> eves;
    z cnt = 1;
    fe(i, ord) {
        if(Max[i] < h + f[i] - 1) {
            eves.pb(mp(max(Max[i] - h + 1, cnt), 1));
            eves.pb(mp(f[i], -1));
        }
        cnt = f[i];
    }
    sort(al(eves));
    z st, cnt2 = 0;
    long long ans = 0;
    fe(i, eves) {
        if(cnt2 == 0) {
            st = i.fs;
        }
        cnt2 += i.sc;
        if(cnt2 == 0) {
            ans += (i.fs - st);
        }
    }
    out << ans;
}