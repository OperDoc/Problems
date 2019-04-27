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

struct event{
	int y, x1, x2;
	event(){}
	event(z a, z b, z c):y(a),x1(b),x2(c){}
	bool operator < (const event& a) {
		return y < a.y || (y == a.y && x1 < a.x1);
	}

};



int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    z n;
    in >> n;
    ve<event> Es;
    fo(i, n) {
    	z a, b, c, d;
    	in >> a >> b >> c >> d;
    	Es.pb(event(b, a, c));
    	Es.pb(event(d, a, c));
    }
    set <pr<z, z>> SEs;
    sort(al(Es));
    z ans = 0;
    fe(i, Es) {
    	if (SEs.find(mp(-i.x1, -i.x2)) != SEs.end()) {
    		ans++;
    		SEs.erase(SEs.find(mp(-i.x1, -i.x2)));
    	} else {
    		if(SEs.lower_bound(mp(-i.x1, -i.x2)) != SEs.end()) {
    			auto res = *SEs.lower_bound(mp(-i.x1, -i.x2));
    			if(!(-res.fs < i.x1 && i.x2 < -res.sc)) {
    				SEs.insert(mp(-i.x1, -i.x2));	
    			}
    		} else {
    			SEs.insert(mp(-i.x1, -i.x2));
    		}
    	}
    } 
    out << ans << nl;
}