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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    z n;
    in >> n;
    ve<z> ns(3 * n);
    fo(i, 3 * n) in >> ns[i];
    sort(al(ns));
    reverse(al(ns));
    long long ans = 0;
    for(z i = 0; i < n; i++) {
        z j = 2 * i + 1;
        ans += ns[j];
    }   
    out << ans << nl;
}