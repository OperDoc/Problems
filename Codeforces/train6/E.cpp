#include <bits/stdc++.h> 

using namespace std;

typedef unsigned long long z;
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

bool comp(z a, z b, z c) {
    if(a * b == 0) return true;
    if(a * b == c) return true;
    return a * b < c && a < (c + b - 1) / b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    z n, A, ans = 0, ii = -1, jj;
    in >> n >> A;
    ve<z> arr(n + 1, 1e18);
    ve<int> ord(n);
    fo(i, n) {in >> arr[i]; ord[i] = i;}
    sort(al(ord), [&](int a, int b){return arr[a] < arr[b];});
    fo(i, n) {
        int l = i, r = n;
        while(r - l > 1){
            int m = (r + l) / 2;
            if(comp(arr[ord[i]], arr[ord[m]], A)) {
                l = m;
            } else {
                r = m;
            }
        }
        if(ans < arr[ord[i]] * arr[ord[l]] && i != l) {
            ans = arr[ord[i]] * arr[ord[l]];
            ii = ord[i];
            jj = ord[l];
        }
    }
    if(ii != -1) {
        out << ans << nl;
        out << ii + 1 << ' ' << jj + 1 << nl; 
    } else {
        out << ans << nl;
    }
}