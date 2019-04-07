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
#define N 100010

ve<z> G[N], ans;
z dp[N];

z go(z v, z p) {
    fe(i, G[v]) {
        if(p != i) dp[v] = dp[v] == 0 ? go(i, v) + 1 : min(dp[v], go(i, v) + 1);
    } 
    if(G[v].size() > 2 || (G[v].size() == 2 && p == -1)) {
        z ii = -1, jj = -1;
        fe(i, G[v]) {
            if(i != p) ii = ii == -1 ? i : (dp[ii] > dp[i] ? i : ii);
        }
        fe(i, G[v]) {
            if(i != p && i != ii) jj = jj == -1 ? i : (dp[jj] > dp[i] ? i : jj);
        }
        ans[v] = dp[ii] + dp[jj] + 2;

    } else ans[v] = 1e9;
    return dp[v];
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    z n, a, b;
    in >> n;
    ans.resize(n, 0);
    fo(i, n - 1) {
        in >> a >> b;
        G[a - 1].pb(b - 1);
        G[b - 1].pb(a - 1);
    }
    go(0, -1);
    ans[0] = G[0].size() == 1 ? dp[0] : ans[0];
    out << (*min_element(ans.begin(), ans.end())) << nl;
}