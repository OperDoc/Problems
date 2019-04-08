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

int make(string &s, char c) {
    bool is = true;
    for(int i = 0; i < s.size(); i++) if(s[i] != c) is = false;
    if(is) return 0;
    string t(s.size() - 1, 'a');
    for(int i = 0; i < s.size() - 1; i++) {
        if(s[i + 1] == c) {
            t[i] = c;
        } else {
            t[i] = s[i];
        }
    }
    return make(t, c) + 1;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    string s;
    in >> s;
    z ans = 1e9;
    for(int i = 0; i != 27; i++) {
        z a = make(s, 'a' + i);
        if(a < ans) ans = a;
    }
    out << ans;
}