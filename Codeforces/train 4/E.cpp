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

bool che(ve<z> & a) {
    bool is = false;
    ff(i, a) {
        if(a[i] != 0 && a[i] != 1) is = true;
        if(is) {
            if(a[i] < 5) return false;
            if(a[i] > 5) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    cout.tie(0);
    string s;
    in >> s;
    ve<z> a(1, 0);
    fo(i, s.size() - 1) {
        a.pb(s[i] - '0');
    }
    int k = -1;
    fo(i, a.size()) {
        if(a[i] != 1 && a[i] != 0) {
            k = i;
            break;
        }
    }
    if(k == -1) {
        fo(i, s.size() - 1) {
            cout << s[i];
        }
        return 0;
    }
    if(a[k - 1] == 1) {
        bool is = true;
        fo(i, a.size()) {
            if(a[i] != 0) is = false;
            if(a[i] == 0 && is) continue;
            if(a[i] != 0) cout << 1;
            else cout << (i>=k);
        }
    } else {
        if(che(a)) {
            a[k - 1] = 1;
            bool is = true;
            fo(i, a.size()) {
                if(a[i] != 0) is = false;
                if(a[i] == 0 && is) continue;
                if(i >= k) cout << 0;
                else cout << a[i];
            }
        } else {
            bool is = true;
            fo(i, a.size()) {
                if(a[i] != 0) is = false;
                if(a[i] == 0 && is) continue;
                if(a[i] != 0) cout << 1;
                else cout << (i>=k);
            }
        }
    }
}
