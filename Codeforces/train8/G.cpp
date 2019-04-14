#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define fo(i, n) for(int i = 0; i < n; i++)
#define fe(i, a) for(auto &i : a)
#define ff(i, a) for(int i = 0; i < a.size(); i++)
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

ve<z> G[1100000];

int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[] = {1, 1, 1, 0, -1, -1, -1, 0};

int d1[1100000], d2[1100000], d3[1100000];

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    z h, w;
    in >> h >> w;
    ve<ve<char>> M(h + 2, ve<char>(w + 2, 'X'));
    for(int i = 1; i <= h; ++i) {
    	for(int j = 1; j <= w; ++j) {
    		in >> M[i][j];
    	}
    }

    for(int i = 1; i <= h; ++i) {
    	for(int j = 1; j <= w; ++j) {
    		for(int k = 0; k < 8; k++) {
    			z ii = i + dy[k];
    			z jj = j + dx[k];
    			if(M[ii][jj] != 'X') {
    				G[i * (w + 2) + j].pb(ii * (w + 2) + jj);
    				G[ii * (w + 2) + jj].pb(i * (w + 2) + j);
    			}
    		}
    	}
    }
}