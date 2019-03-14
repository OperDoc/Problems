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

typedef complex<z> P;
#define X real()
#define Y imag()

ve<P> Ps;
bitset<300> bts[301][301];

long long cd(P &a, P &b) {
    return a.X * b.Y - b.X * a.Y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    z n;
    Ps.resize(n);
    fo(i, n) in >> Ps[i].X >> Ps[i].Y;
    
    
}