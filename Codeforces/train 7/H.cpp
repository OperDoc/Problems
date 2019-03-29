#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define fo(i, n) for(int i = 0; i != n; i++)
#define fe(i, a) for(auto &i : a)
#define ff(i, a) for(int i = 0; i != a.size(); i++)
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
    string s;
    in >> s;
    if(s.size() < 3) {
        out << "NO SOLIUTON" << nl;
        return 0;
    }
    char c = s[1];
    bool is = true;
    for(z i = 2; i != s.size() - 1; i++) if(s[i] != c) is = false;
    if(is) {
        out << "NO SOLIUTON" << nl;
        return 0;
    } 
    out << s[0];
    for(z i = 2; i != s.size() - 1; i++) out << s[i];
    out << s[1] << s[s.size() - 1] << nl;
}