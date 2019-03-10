#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define fo(i, n) for(int i = 0; i < n; i++)
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
    string s, t;
    cin >> s >> t;
    z cnt1 = 0, cnt2 = 0;
    fo(i,s.size()){cnt1+=(s[i]=='b');cnt2+=(t[i]=='b');}
    if(cnt1 != cnt2) {cout << -1 << nl; return 0;}
    ve<z> b1, b2;
    fo(i, s.size()){
        if(s[i] == 'b') b1.pb(i);
        if(t[i] == 'b') b2.pb(i);
    }
    z ans = 0;
    fo(i, b1.size()) {
        ans += abs(b1[i] - b2[i]);
    }
    out << ans << nl;
}

