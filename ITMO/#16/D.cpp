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

typedef complex<z> P;

ve<P> Ps;
bitset<301> bts[301][301];
int ans[301];

long long Cd(P a, P b) {
    return a.real() * b.imag() - b.real() * a.imag();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    z n;
    in >> n;
    Ps.resize(n);
    long double a, b;
    fo(i, n) {
        in >> a >> b;
        Ps[i] = complex<z>(a, b);
    }
    fo(i, n) {
        for(int j = i + 1; j < n; j++) {
            for(int ii = 0; ii < n; ii++) {
                if(ii != j && ii != i) {
                    bool is = (Cd(Ps[j] - Ps[i], Ps[ii] - Ps[i]) > 0);
                    bts[i][j][ii] = is;
                    bts[j][i][ii] = !is;
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int ii = j + 1; ii < n; ii++) {
                bool is = (Cd(Ps[j] - Ps[i], Ps[ii] - Ps[i]) > 0);
                if(!is)swap(j, ii);
                ans[(bts[i][j] & bts[j][ii] & bts[ii][i]).count()]++;
                if(!is)swap(j, ii);
            }
        }
    }
    fo(i, n - 2) {
        out << ans[i] << nl;
    }
}