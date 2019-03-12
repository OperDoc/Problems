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
#define mod 1000000007

long long dp[5010][5010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    in >> s >> t;
    for(int i = s.size() - 1; i >= 0; i--) {
        for(int j = t.size() - 1; j >= 0; j--) {
            dp[i][j] = dp[i][j + 1];
            if(s[i] == t[j]) {
                dp[i][j] = (dp[i][j] + dp[i + 1][j + 1] + 1) % mod;
            }
        }
    }
    long long ans = 0;
    fo(i, s.size()) ans = (ans + dp[i][0]) % mod;
    out << ans << nl;
}