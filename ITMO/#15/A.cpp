#include <bits/stdc++.h> 

using namespace std;

typedef long long z;
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
#define mod 1000000007

long long dp[5010][5010];

long long bin_pow(long long a, long long b){
    if(b == 1 || b == 0) return b == 0 ? 1 : a % mod;
    if(b % 2 == 0){
        long long ans = bin_pow(a, b / 2);
        return (ans * ans) % mod;
    }
    return (bin_pow(a, b - 1) * a) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    z n, k;
    in >> n >> k; k--;
    ve<z> c(n, 1), arr(n);
    fe(i, arr) in >> i, i %= mod;
    for(z i = 1; i < n; i++) {
        c[i] = ((c[i - 1] * ((k + i) % mod)) % mod * bin_pow(i, mod - 2)) % mod;
    }
    z ans;
    for(z i = 0; i < n; i++) {
        ans = 0;
        for(z j = i; j >= 0; j--) {
            ans = ans + arr[j] * c[i - j] % mod;
            ans %= mod;
        }
        out << ans << ' '; 
    }
}