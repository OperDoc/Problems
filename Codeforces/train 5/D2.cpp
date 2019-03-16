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
    z n, h;
    in >> n >> h;
    ve<z> g(n), f(n), ord(n), Max(n);
    fo(i, n) in >> g[i] >> f[i];
    fo(i, n) ord[i] = i;
    sort(al(ord), [&](z i, z j){return f[i] < f[j];});
    Max[ord[n - 1]] = g[ord[n - 1]];
    for(z i = n - 2; i >= 0; i--) Max[ord[i]] = max(g[ord[i]], Max[ord[i + 1]]); 
    z End = f[ord[n - 1]], Start = 1;
    fe(i, ord) {
        if(Max[i] >= f[i] + h - 1) {
            Start = f[i];
        } else {Start = max(Max[i] - h + 1, Start); break;}
    }
    long long ans = 0;
    fo(i, n) if(f[i] > Start) ans += f[i] - Start;
    out << ans << nl;
}