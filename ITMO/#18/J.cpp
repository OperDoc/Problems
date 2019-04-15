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

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    z n;
    in >> n;
    z a, b;
    in >> a >> b;
    z t = 0, ans = 0;
    t += a;
    t += b;
    while(t <= n * 60){
    	ans += 1;
    	t += max(a - b, 0);
    	t += b;
    }
    out << ans << nl;
}