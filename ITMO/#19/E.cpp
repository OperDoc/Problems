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

z n;
pr<z, z> ps[100010];

int def(int H) {
	H = 2 * H + 1;
	ve<pr<z, z>> r, l;
	fo(i, n) {
		if(ps[i].fs > H) {
			r.pb(ps[i]);
		} else {
			l.pb(ps[i]);
		}
	}
	z lcntup = l.size(), lcntdown = 0;
	z rcntup = r.size(), rcntdown = 0;
	z ans = max(l.size(), r.size());
	for(int i = 0; i < n; i++) {
		if(ps[i].fs > H) {
			
		} else {
			
		}
	}
}


int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    in >> n;
    fo(i, n){
    	in >> ps[i].fs >> ps[i].sc;
    }
    sort(ps, ps + n, [](pr<z, z>& a, pr<z, z>& b){return a.sc < b.sc || (a.sc == b.sc && a.fs < b.fs);});
    z l = 0, r = 1e9;
    while(r - l  > 3) {
    	z m1 = (r + 2 * l) / 3;
    	z m2 = (2 * r + l) / 3;
    	if(def(m1) < def(m2)) {
    		r = m2;
    	} else {
    		l = m1;
    	}
    }

}	