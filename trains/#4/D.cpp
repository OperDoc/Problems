#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define fo(i, n) for(int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define al(a) a.begin(),a.end() 
#define pr pair
#define ve vector
#define fs first
#define sc second
#define in cin
#define out cout 
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    z m, d, k;
    in >> m >> d;
    k = d;
    ve<pr<z, z>> ds;
    for(z i = 2; i * i <= k; i++) {
        z cnt = 0;
        while(k % i == 0) {cnt++; k/=i;}
        ds.pb(mp(i, cnt));
    }
    if(k != 1) ds.pb(mp(k, 1));
    fo(i, ds.size()) {
        ds[i].sc = (ds[i].sc + m - 1) / m;
    }
    long long ans = 1;
    fo(i, ds.size()) {
        fo(j, ds[i].sc) {
            ans *= (long long)ds[i].fs;
        }
    }
    cout << ans << nl;
}

