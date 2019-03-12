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

z n, m;
ve<z> g[10010], G[10010];
bool u[10010], u2[10010];
int dfs(int v) {
    z res = 1;
    u[v] = true;
    fe(i, g[v]) {
        if(!u[i]) res += dfs(i);
    }
    return res;
}
int dfs2(int v) {
    z res = 1;
    u2[v] = true;
    fe(i, G[v]) {
        if(!u2[i]) res += dfs(i);
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    in >> n >> m;
    ve<ve<z>> mtr(n + 4, ve<z>(m + 4, -1e9));
    z a, b, c, d;
    fo(i, n) {
        fo(j, m){
            in >> mtr[i + 2][j + 2];
        }
    }
    in >> a >> b >> c >> d;
    mtr[a - 1][b - 1]--;
    fo(i, n) {
        fo(j, m) {
            if(mtr[i + 2][j + 2] == mtr[i + 2][j + 3])g[i * n + j].pb(i * n + j + 1);
            if(mtr[i + 2][j + 2] == mtr[i + 2][j + 1])g[i * n + j].pb(i * n + j - 1);
            if(mtr[i + 2][j + 2] == mtr[i + 3][j + 2])g[i * n + j].pb(i * n + j + n);
            if(mtr[i + 2][j + 2] == mtr[i + 1][j + 2])g[i * n + j].pb(i * n + j - n);

            if(mtr[i + 2][j + 2] == mtr[i + 2][j + 3])G[i * n + j].pb(i * n + j + 1);
            if(mtr[i + 2][j + 2] == mtr[i + 2][j + 1])G[i * n + j].pb(i * n + j - 1);
            if(mtr[i + 2][j + 2] == mtr[i + 3][j + 2])G[i * n + j].pb(i * n + j + n);
            if(mtr[i + 2][j + 2] == mtr[i + 1][j + 2])G[i * n + j].pb(i * n + j - n);

            if(mtr[i + 2][j + 2] == mtr[i + 2][j + 4])G[i * n + j].pb(i * n + j + 2);
            if(mtr[i + 2][j + 2] == mtr[i + 2][j])G[i * n + j].pb(i * n + j - 2);
            if(mtr[i + 2][j + 2] == mtr[i + 4][j + 2])G[i * n + j].pb(i * n + j + 2 * n);
            if(mtr[i + 2][j + 2] == mtr[i][j + 2])G[i * n + j].pb(i * n + j - 2 * n);
        }
    }
    z res = dfs((a - 1) * n + b - 1);
    if(u[(c - 1) * n + d - 1]) {
        res = dfs2((a - 1) * n + b - 1);
    }
    out << res;
}
