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

int main() {
    //	ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    z a, b, c, x, y, ans = 0;
    in >> a >> b >> c >> x >> y;
    ans = min(a + b, 2 * c) * min (x, y);
    if(x > y) {
    	ans += abs(x - y) * min(2 * c, a);
    } else {
    	ans += abs(x - y) * min(2 * c, b);
    }
    out << ans << nl;
}