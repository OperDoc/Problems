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
#define M (r + l) / 2
#define cL 2 * i + 1
#define cR 2 * i + 2

struct e {
	z t, i, type;
	e(z a, z b, z c):t(a),i(b),type(c){}
	bool operator <(e& a){
		return t < a.t || (t == a.t && type < a.type);
	}
};

z t[1600320];

ve<e> es;

z vals[200010], ans[200010];

pr<z, z> qs[200010];

ve<z> mins;

z k = -1;

z st(z i = 0, z l = 0, z r = k){
	return t[i] = r - l == 1 ? mins[l] : min(st(cL, l, M), st(cR, M, r));
}

z tMin(z al, z ar, z i = 0, z l = 0, z r = k){
	if(ar <= l || r <= al) return 1e9;
	if(al <= l && r <= ar) return t[i];
	return min(tMin(al, ar, cL, l, M), tMin(al, ar, cR, M, r));
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0), cout.tie(0);
    z n;
    in >> n;
    fo(i, n) {
    	z a, b;
    	in >> a >> b;
    	es.pb(e(a, i, -1));
    	es.pb(e(b, i,  1));
    }
    sort(al(es));
    z cnt1 = 0, cnt2 = 0;
    fe(i, es){
    	if(i.type == -1) {
    		cnt2++;
    		vals[i.i] -= cnt1;
    	} else {
    		cnt1++;
    		vals[i.i] += cnt2 - 1;
    	}
    }
    multiset<z> s;
    for(int i = 0; i < es.size(); i++) {
    	if(es[i].type == -1) {
    		s.insert(vals[es[i].i]);
    		qs[es[i].i].fs = i;
    	} 
    	mins.pb(*s.begin());
    	if(es[i].type == 1) {
    		qs[es[i].i].sc = i;	
    		if(s.find(vals[es[i].i]) != s.end())s.erase(s.find(vals[es[i].i]));
    	}
    }
    k = mins.size();
    st();
    fo(i, n) {
    	ans[i] = tMin(qs[i].fs, qs[i].sc);
    }
    fo(i, n) {
    	out << ans[i] << nl;
    }
}