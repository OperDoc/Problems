#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define fo(i, n) for(int i = 0; i < n; i++)
#define fe(i, n) for(auto &i : n)
#define ff(i, n) for(int i = 0; i < n.size(); i++)
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
    z k, a, b;
    string s;
    in >> k >> a >> b >> s;
    if(k * a > s.size() || k * b < s.size()) {
        out << "No solution" << nl;
        return 0;
    }

    if(k == 1) {
        out << s;
    }
    z r = -1;
    for(int i = a; i <= b; i++) {
        z u = s.size() - i * (k - 1);
        if(a <= u && u <= b) {
            r = i;
            break;
        }
    }
    z i = 0;
    for(z l = 0; l < k - 1; l++){
        for(z j = 0; j < r; j++,i++) {
            out << s[i];
        }
        out << nl;
    }
    for(;i < s.size(); i++){
        out << s[i];
    }
    out << nl;
}