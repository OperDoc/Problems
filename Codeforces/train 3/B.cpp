#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define ffor(i, n) for(int i = 0; i < n; i++)
#define mP make_pair
#define pB push_back
#define all(a) a.begin(),a.end() 
#define pr pair
#define vec vector
#define fs first
#define sc second 

int dp[1010][1010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    z n, k;
    cin >> n >> k;
    vec<z> a(n);
    ffor(i, n) cin >> a[i];
    ffor(i, 1000) {
        dp[0][i] = abs(a[0] - i);
    }
    for(z i = 1; i < n; i++) {
        ffor(j, 1010) {
            dp[i][j] = 1e9;
            for(z ii = max(0, j - k); ii <= min(1009, j + k); ii++) {
                dp[i][j] = min(dp[i][j], dp[i - 1][ii] + abs(j - a[i]));
            }
        }
    }
    z ans = 1e9;
    for(z i = 0; i < 1010; i++) {
        ans = min(ans, dp[n - 1][i]);
    }
    cout << ans;
}