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

struct e{
	z a, b, c;
	e(z a, z b, z c):a(a),b(b),c(c){}
	bool operator <(const e& a) {
		return c < a.c;
	}
};

int dist(z a, z b, z c, z d) {
	return (a - c) * (a - c) + (b - d) * (b - d);
}

int p[1010];

int Mget(int i){
	if(p[i] == i) return i;
	return p[i] = Mget(p[i]);
}

bool Munion(int i, int j){
	if(i != j) {
		p[j] = i;
	}
	return i != j;
} 

ve<e> es;

pair<z, z> Ps[1010];

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    z n;
    in >> n;
    fo(i, n) {
    	p[i] = i;
    	in >> Ps[i].fs >> Ps[i].sc;
    }
    fo(i, n) {
    	for(int j = i + 1; j < n; j++) {
    		es.pb(e(i, j, dist(Ps[i].fs, Ps[i].sc, Ps[j].fs, Ps[j].sc)));
    	}
    }
    sort(al(es));
    int ans;
    for(int i = 0; i < es.size(); i++) {
    	z a = Mget(es[i].a);
    	z b = Mget(es[i].b);
    	if(Munion(a, b)) {
    		ans = es[i].c;
    	}
    }
    out << ans << nl;
}