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
#define inv(a) bin_pow(a, 1e9 + 5)
long long mod = 1e9 + 7;
 
long long dp[1000010];
 
long long bin_pow(long long a, long long b){
    if(b == 1 || b == 0) return b == 0 ? 1 : a % mod;
    if(b % 2 == 0){
        long long ans = bin_pow(a, b / 2);
        return (ans * ans) % mod;
    }
    return (bin_pow(a, b - 1) * a) % mod;
}

long long fact[110000];

long long C(z a, z b) {
	return (dp[a] * inv((dp[b] * dp[a - b]) % mod)) % mod;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    for(int i = 0; i < 1000001; i++)
    {
        dp[i] = i == 0 ? 1 : (dp[i - 1] * i) % mod;
    }
    z T;
    in >> T;
    for(z t = 0; t < T; t++) {
    	z a, b;
    	in >> a >> b;
    	if(a > 2 && b > 2)
    		out << (C(a + 1, 4) * C(b + 1, 4)) % mod << nl;
    	else
    		out << 0 << nl;
    }
}
