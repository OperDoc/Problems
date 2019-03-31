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

ve<ve<z>> T(1, ve<int>(26, -1));
ve<int> Ends(1, false);
ve<z> dp(1, 0);

inline z go(z curr, char a) {
    return T[curr][a - 'a'];
}

inline z add(z curr, char a) {
    T[curr][a - 'a'] = T.size();
    T.pb(ve<z>(26, -1));
    Ends.pb(0);
    dp.pb(0);
    return go(curr, a);
}

int q(string &s, z curr = 0, z i = 0) {
    if(i == s.size()) return dp[curr];
    z next = go(curr, s[i]);
    if(next == -1) return 0;
    return q(s, next, i + 1);
}

void add(string &s, z curr = 0, z i = 0) {
    if(i == s.size()) {
      Ends[curr] = true;
    } else {
        z next = go(curr, s[i]);
        if(next == -1) {
            next = add(curr, s[i]);
        }
        add(s, next, i + 1);
    }
    dp[curr] += 1;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    z n, m, a;
    in >> n;
    string s;
    fo(i, n){
        in >> s;
        add(s);
        //out << 1;
    }
    in >> m;
    fo(i, m) {
        in >> a >> s;
        if(a == 1) {
            add(s);
        } else {
            out << q(s) << nl;
        }
    }
}