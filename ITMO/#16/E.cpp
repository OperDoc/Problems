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
const long long mod = 1e9 + 9;

long long dp[1010][1010][15];

long long add(long long a, long long b) {
    return ((a + b) % mod + mod) % mod;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    z n, m, k;
    in >> n >> m >> k;
    ve<z> a(n), b(m);
    fe(i, a) in >> i;
    fe(i, b) in >> i;
    sort(al(a));
    sort(al(b));
    fo(i, n + 1) 
        fo(j, m + 1) 
            dp[i][j][0] = 1;

    fo(i, n){
        fo(j, m){
            fo(ii, k){
                dp[i + 1][j + 1][ii + 1] = add(add(dp[i + 1][j][ii + 1], dp[i][j + 1][ii + 1]),  -dp[i][j][ii + 1]);
                if(a[i] > b[j]) dp[i + 1][j + 1][ii + 1] = add(dp[i + 1][j + 1][ii + 1], dp[i][j][ii]);
            }
        }
    }
    out << (dp[n][m][k] + mod) % mod << nl;
}