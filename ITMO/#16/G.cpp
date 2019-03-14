#include <bits/stdc++.h> 

using namespace std;

typedef long long z;
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
    z n, x, a, b;
    char c;
    in >> n >> x;
    z l = 0, r = 1e18;
    ve<z> ns(n);
    fo(i, n) {
        in >> c >> a;
        b = c == '-' ? -1 : 1;
        ns[i] = b * a;
    }
    bool pre = true;
    z cn = x;
    fo(i, n) {
        cn += ns[i];
        if(cn < 0) pre = false;
    }
    if(pre) {
        out << 0;
        return 0;
    }
    while(r - l > 1) {
        z m = (r + l) / 2;
        z cnt = m + x;
        bool is = true;
        fo(i, n) {
            cnt += ns[i];
            if(cnt < 0) is = false;
        }
        if(is) {
            r = m;
        } else {
            l = m;
        }
    }
    out << r;
}