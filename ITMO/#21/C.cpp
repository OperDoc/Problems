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

ve<z> G[100010];
z D[100010];

void bfs(int s)/*O(E)*/{
    queue<int> q;
    D[s] = 0;
    q.push(s);
    while(!q.empty()){
        int v = q.front();

        q.pop();
        for(auto i:G[v]) {
        	if(D[i] == 1e9){
        		D[i] = D[v] + 1;
        		q.push(i);
        	}
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
  z n, m;
  in >> n >> m;
    set<pr<z, z>> s;
    fo(i, m) {
    	z a, b;
    	in >> a >> b;
    	a--;b--;
    	s.insert(mp(a, b));
    	s.insert(mp(b, a));
    }
    z a, b;
    in >> a >> b;
    a--;b--;
    s.erase(mp(a, b));
    s.erase(mp(b, a));
    fe(i, s) {
    	G[i.fs].pb(i.sc);
    }
    fo(i, n) D[i] = 1e9;
    bfs(a);
    if(D[b] == 1e9) {
    	out << "Infinity" << nl;
    } else {
    	out << D[b] - 1 << nl;
    }
}
