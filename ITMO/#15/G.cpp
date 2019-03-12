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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    z n, k, h;
    in >> n >> k >> h;
    ve<z> m(n), v(n), ord(n), ans;
    fo(i, n) in >> m[i];
    fo(i, n) in >> v[i];
    iota(al(ord), 0);
    sort(al(ord), [&](int i, int j){return mp(m[i], v[i]) < mp(m[j], v[j]);});
    double l = 0, r = 1.5e9;
    fo(q, 100) {
        double m = (l + r) / 2;
        ve<z> res;
        fe(i, ord) {
            if(v[i] * m >= (res.size() + 1) * h) {
                res.pb(i);
                if(res.size() == k) {
                    break;
                }
            }
        }
        if(res.size() == k) {
            r = m; ans = res;
        } else { l = m; }
    }
    fe(i, ans){
        cout << i + 1 << ' ';
    }
}