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

ve<z> g[100010];

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    z n, m;
    in >> n >> m;
    fo(i, m) {
    	z a, b;
    	in >> a >> b;
    	g[a - 1].pb(b - 1);
    	g[b - 1].bp(a - 1);
    }
    ve<bool> is(n, false), is1(n, false);
    z T;
    in >> T;
    fo(i, T) {
    	z t;
    	in >> t; t--;
    	if(!is[t]) {
    		is1[t] = true;
    	}
    	fe(i, g[t]) {
    		is[i] = true;
    	} 
    }
    ve<z> arr;
    fo(i, n) {
    	if(is1[i]) {
    		arr.pb(i);
    	}
    }
    ve<bool> isAns(n, false);
    fo(i, n) {
    	sort(al(g[i]));
    	z j = 0;
    	fe(v, g[i]) {
    		if(j < arr.size() && v == arr[j]) j++;
    	}
    	isAns[i] = (j == arr.size());
    }
    
}