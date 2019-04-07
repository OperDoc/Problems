#include <bits/stdc++.h> 

using namespace std;

typedef long double z;
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
    int n, m, k;
    in >> n >> m;
    k = max(n, m);
    ve<z> a(k, 1), b(k, 1);
    fo(i, n) in >> a[i];
    fo(i, m) in >> b[i];
    z ans = 1;
    fo(i, k) {
        ans *= a[i];
        ans /= b[i];
    }
    long long res = ans;
    cout << res;
}