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

struct ev{
    z t, x, i;
    ev(z t, z x, z i):t(t),x(x),i(i){} 
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    z n, a, b;
    in >> n;
    ve<ev> arr;
    ve<pr<z, z>> ans(n, mp(-1, -1));
    fo(i, n) {
        in >> a >> b;
        arr.pb(ev(b, a, i));
    }
    sort(al(arr), [&](ev &a, ev &b){return a.x < b.x;});
    z curr = -1;
    fo(i, n) {
        if(curr == -1) {
            curr = i;
            ans[arr[curr].i].fs = arr[curr].x;
            ans[arr[curr].i].sc = arr[curr].t;
        } else {
            if(arr[curr].t < arr[i].t) {
                ans[arr[curr].i].sc = min(arr[i].x, ans[arr[curr].i].sc);
                curr = i;
                ans[arr[curr].i].fs = arr[curr].x;
                ans[arr[curr].i].sc = arr[curr].t;
            }
        }
    }
    fo(i, n) {
        out << ans[i].fs << ' ' << ans[i].sc << nl;
    }
}