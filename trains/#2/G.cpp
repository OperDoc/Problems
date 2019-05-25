#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

long long f(long long k, long long size, long long pos) {
    long long ss = size / 2;
    return k * (size + 1) + min(pos + 1, size - pos) * ss * (size % 2);
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int mod = 1000000007;
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(n == 1) {
            int num = (int) s[0];
            cout << "Case " << t+1 << ": ";
            cout << num;
            cout << '\n';
            continue;
        }
        vector<long long> g(n), ks(n), anses(n);
        long long ans = 0;
        g[0] = n / 2;
        g[n - 1] = n / 2;
        for(int i = 1; i < n / 2; i++) {
            g[i] = g[i - 1] + n / 2 - min(i + 1, n - i) + 1;
            g[n - i] = g[i - 1] + n / 2 - min(i + 1, n - i) + 1;
        }
        if(n % 2 == 1) {
            g[n / 2 + 1] = g[n / 2];
        }
        for(int i = 0; i < n; i++) {
            ks[i] = f(g[i] % mod, n, i) % mod;
            anses[i] = (ks[i] * s[i]) % mod;
            ans = (ans + anses[i]) % mod;
        } 
        for(int i = 0; i < n; i++) {
            cout << g[i] << ' ';
        }
        cout << endl;
        for(int i = 0; i < n; i++) {
            cout << ks[i] << ' ';
        }
        cout << endl;
        cout << "Case " << t+1 << ": ";
        cout << ans;
        cout << '\n';
    }
    return 0;
}