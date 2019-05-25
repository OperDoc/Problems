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

ve<pr<z, z>> g[20010], rg[20010];

z d[210][20010], rd[210][20010];

void path(int s, int ind) {
	fo(i, 20010) d[ind][i] = 1e9;
	d[ind][s] = 0;
	set<pr<z, z>> q;
	q.insert(mp(d[ind][s], s));
	while(!q.empty()) {
		z v = q.begin()->second; 
		q.erase(q.begin());
		fe(i, g[v]) {
			if(d[ind][v] + i.sc < d[ind][i.fs]) {
				q.erase(mp(d[ind][i.fs], i.fs));
				d[ind][i.fs] = d[ind][v] + i.sc;
				q.insert(mp(d[ind][i.fs], i.fs));
			}
		}
	}
}

void rpath(int s, int ind) {
	fo(i, 20010) rd[ind][i] = 1e9;
	rd[ind][s] = 0;
	set<pr<z, z>> q;
	q.insert(mp(rd[ind][s], s));
	while(!q.empty()) {
		z v = q.begin()->second; 
		q.erase(q.begin());
		fe(i, rg[v]) {
			if(rd[ind][v] + i.sc < rd[ind][i.fs]) {
				q.erase(mp(rd[ind][i.fs], i.fs));
				rd[ind][i.fs] = rd[ind][v] + i.sc;
				q.insert(mp(rd[ind][i.fs], i.fs));
			}
		}
	}
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    z n, m, k, q;
    in >> n >> m >> k >> q;
    fo(i, m) {
    	z a, b, c;
    	in >> a >> b >> c;
    	g[a - 1].pb(mp(b - 1, c));
    	rg[b - 1].pb(mp(a - 1, c));
    }
    ve<z> ks(k);
    fo(i, k) {
    	in >> ks[i];
    	ks[i]--;
    }
    fo(i, k) {
    	path(ks[i], i);
    }
    fo(i, k) {
    	rpath(ks[i], i);
    }
    long long ans = 0, cnt = 0;
    fo(i, q) {
    	z a, b;
    	in >> a >> b;
    	z mmin = 1e9;
    	fo(i, k) {
    		if(mmin > rd[i][a - 1] + d[i][b - 1]) {
    			mmin = rd[i][a - 1] + d[i][b - 1];
    		}
    	}
    	if(mmin != 1e9) {
    		cnt++;
    		ans += mmin;
    	}
    }
    out << cnt << ' ' << ans << nl;

}