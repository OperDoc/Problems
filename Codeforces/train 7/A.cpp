#include <bits/stdc++.h>

using namespace std;

typedef long long z;
#define fo(i, n) for(int i = 0; i != n; i++)
#define fl(i, n) for(int i = 0; i != n.size(); i++)
#define fe(i, n) for(auto &i : n)
#define al(n) n.begin(),n.end()
#define ve vector
#define pb push_back
#define mp make_pair
#define pr pair
#define fs first
#define sc second
#define in cin
#define out cout
#define nl '\n'

int main(){
    z n, l, r;
    in >> n >> l >> r;
    ve<z> arr;
    for(z i = 0; (1ll<<i) <= n; i++) {
        if(n & (1ll<<i)) {
            arr.pb(1);
        } else {
            arr.pb(0);
        }
    }
    //reverse(al(arr));
    
    bool ans = true;
    for(int i = l; i <= min((long long)arr.size() - 1, r); i++){
        if(arr[i]) ans = false;
    }
    if(ans) {
        out << "YES" << nl;
    } else {
        out << "NO" << nl;
    }
}