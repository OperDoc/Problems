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

char g[10][10];

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    z n, m;
    in >> n >> m;
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < m; j++) {
    		in >> g[i][j];
    	}
    }
    int x = 0, y = 0;
    while(g[x][y + 1] == '#' || g[x + 1][y] == '#') {
    	g[x][y] = '$';
    	if(g[x][y + 1] == '#') y++;
    	else x++;
    }
    g[x][y] = '$';
    bool is1 = (x == (n - 1)) && (y == (m - 1)), is2 = true;
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < m; j++) {
    		if(g[i][j] == '#') is2 = false;
    	}
    }
    if(is1 && is2) {
    	out << "Possible" << nl;
    } else {
    	out << "Impossible" << nl;
    }
}