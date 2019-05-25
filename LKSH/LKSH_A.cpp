#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define fo(i, n) for(int i = 0; i != n; ++i)
#define fe(i, a) for(auto &i : a)
#define ff(i, a) for(int i = 0; i != a.size(); ++i)
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

int n, m;
ve<z> g[100010], G[100010];
ve<z> used, color, order;
ve<long long> cnt_V, cnt_E;

void dfs1(int v) {
	used[v] = true;
	fe(i, g[v]) if(!used[i]) dfs1(i);
	order.pb(v);
}

void dfs2(int v, int c) {
	color[v] = c;
	fe(i, G[v]) if(color[i] == -1) dfs2(i, c);
}

int main() {
	set<pr<z,z>> Set;
    //os_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    in >> n >> m;
    fo(i, m) {
    	z a, b;
    	in >> a >> b;
    	if(Set.insert(mp(a, b)).sc) {
    		g[a - 1].pb(b - 1);
    		G[b - 1].pb(a - 1);	
    	}
    	
    }
    used.assign(n, 0);
    fo(i, n) if(!used[i]) dfs1(i);
    color.assign(n, -1);
    fo(i, n) {
    	z v = order[n - 1 - i];
    	if(color[v] == -1) dfs2(v, i);
    }
	cnt_V.assign(n, 0);
	fo(i, n) {
		cnt_V[color[i]]++;
	}
    cnt_E.assign(n, 0);
    fo(i, n) {
    	fe(j, g[i]) {
    		cnt_E[color[i]] += (color[i] == color[j]);
    	}
    }
    long long ans = 0;
    fo(i, n) {
    	long long cV = cnt_V[i];
    	long long cE = cnt_E[i];
    	long long dans = cV * (cV - 1) - cE;
    	//if(dans < 0 && cV * (cV - 1) > 0 && cV * (cV - 1) < cE) {while(true){}}
    	ans += dans;
    }
    out << ans << nl;
}




