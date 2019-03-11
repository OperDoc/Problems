#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define fo(i, n) for(int i = 0; i < n; i++)
#define fe(i, n) for(auto &i : n)
#define ff(i, n) for(int i = 0; i < n.size(); i++)
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

z col[300];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    z n, a, b, nn;
    in >> n;
    nn = n * (n - 1) / 2;
    ve<ve<z>> ns(nn), ans(300);
    fo(i, nn) {
        in >> a;
        fo(j, a){
            in >> b;
            ns[i].pb(b);
        }
        sort(al(ns[i]));
    }
    if(nn == 1) {
        out << 1 << ' ' << ns[0][0] << nl << ns[0].size() - 1 << ' ';
        for(z i = 1; i < ns[0].size(); i++) {
            out << ns[0][i] << ' ';
        }
        out << nl;
        return 0;
    }
    ve<z> res;
    set_intersection(al(ns[0]), al(ns[1]), back_inserter(res));
    fe(i, res){
        col[i] = 1;
    }
    z cnt = 2;
    fo(i, nn) {
        bool is = false, is2 = false;
        ff(j, ns[i]) {
            if(col[ns[i][j]] != 0) is = true;
            if(col[ns[i][j]] == 0) is2 = true;
        }
        if(is && is2) {
            ff(j, ns[i]) {
                if(col[ns[i][j]] == 0) col[ns[i][j]] = cnt;
            }
        }
        cnt += (is && is2);
    }
    fo(i, 300) {
        if(col[i]){
            ans[col[i] - 1].pb(i);
        }
    }
    fo(i, 300) {
        if(ans[i].size() != 0) {
            out << ans[i].size() << ' ';
            ff(j, ans[i]) {
                out << ans[i][j] << ' ';
            }
            out << nl;
        }
    }
}