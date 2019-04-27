#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define fo(i, n) for(int i = 0; i != n; ++i)
#define fe(i, a) for(auto &i : a)
#define ff(i, a) for(int i = 0; i != a.size(); ++i)
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

struct edge{
    long long a, b, c;
    edge(z a, z b, z c):a(a),b(b),c(c){}
    bool operator < (const edge& a) {
        return c < a.c;
    } 
};

int p[250000], vs[250000], cnt[250000];
int n, m, k;
int mtr[500][500];
ve<edge> es;

int mGet(int i){return p[i] == i ? i : (p[i] = mGet(p[i]));}

void mUnion(int i, int j) {
    if(i == j) return;
    p[j] = i;
    vs[i] += vs[j];
    cnt[i] += cnt[j];
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    in >> n >> m >> k;
    fo(i, n) {
        fo(j, m) {
            in >> mtr[i][j];
        }
    }
    fo(i, n) {
        fo(j, m) {
            in >> cnt[i * m + j];
            vs[i * m + j] = 1;
            p[i * m + j] = i * m + j;
        }
    }
    fo(i, n) {
        fo(j, m) {
            int v = i * m + j;
            if(i != 0) {
                es.pb(edge(v, v - m, abs(mtr[i][j] - mtr[i - 1][j])));
            }
            if(j != 0) {
                es.pb(edge(v, v - 1, abs(mtr[i][j] - mtr[i][j - 1])));
            }
        }
    }
    sort(al(es));
    long long res = 0;
    fe(e, es){
        int i = mGet(e.a);
        int j = mGet(e.b);
        int sum = (vs[i] < k ? cnt[i] : 0) + (vs[j] < k ? cnt[j] : 0);
        mUnion(i, j);
        if(vs[i] >= k) res += sum * e.c;
    }
    out << res << nl;
}