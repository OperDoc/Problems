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
//#define or ||
//#define and && 

struct e{
	z t, i, type;
	e(z a, z b, z c):t(a),i(b),type(c){}
	bool operator < (e a) {
		return t < a.t or (t == a.t and type > a.type); 
	}
};

bool isIn(z a, z b, z c){
	return a <= b and b <= c;
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);            
	//cout.tie(0);
	z n, c, k;
	in >> n >> c >> k;
	ve<e> es;
	fo(i, n){
		z t;
		in >> t;
		es.pb(e(t, i, 1));
		es.pb(e(t + k, i, -1));
	}
	sort(al(es));
	z cnt = 0, ans = 0, lastT = -1000;
	fe(i, es) {
		if(i.type == -1 and !isIn(i.t - k, lastT, i.t) ){
			cnt = 0;
			ans++;
			lastT = i.t;
			//out << lastT << nl;
		}
		if(i.type == 1){
			cnt++;		
		}	
		if (cnt == c){
			cnt = 0;
			ans++;
			lastT = i.t;
			//out << lastT << nl;
		}	
	}
	out << ans << nl;		
}