#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define fo(i, n) for(int i = 0; i < n; i++)
#define fe(i, a) for(auto &i : a)
#define ff(i, a) for(int i = 0; i < a.size(); i++)
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
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    z n, h;
    in >> n >> h;
    ve<z> g(n), f(n);
    fo(i, n) in >> g[i] >> f[i];
    z cnt = 1;
    long long ans = 0;
    fo(i, n) {
        z next = 1e9;
        fo(i, n) if(f[i] > cnt && f[i] < next) next = f[i];
        z Max = 0;
        fo(i, n) if(f[i] > cnt && g[i] > Max) Max = g[i];
        if(next + h - 1 <= Max) {
            cnt = next; 
        } else {
            cnt = max(Max - h + 1, cnt);
            break;
        }
    }
    fo(i, n) if(f[i] > cnt) ans += f[i] - cnt;
    out << ans << nl;
}