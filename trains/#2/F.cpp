#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

bool isP[10000010], ans[10000010];
int sum[10000010];

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    isP[0] = false;
    isP[1] = false;
    for(int i = 2; i < 10000010; i++){
        if(!isP[i]){
            for(long long j = (long long)i * i; j < 10000010; j += i) {
                isP[j] = true;
            }
        }
    }
    ans[0] = false;
    ans[1] = true;
    for(int i = 2; i < 10000010; i++){
        if(!isP[i]){
            ans[i] = 1;
            for(long long j = i; j * i < 10000010; j += 1) {
                ans[i * j] = !isP[j];
            }
        }
    }
    sum[0] = ans[0];
    for(int i = 1; i < 10000010; i++) {
        sum[i] = sum[i - 1] + ans[i];
    }
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        int n, res, GCD;
        cin >> n;
        res = sum[n];
        GCD = gcd(res, n);
        res = res / GCD;
        n = n / GCD;
        cout << "Case " << t+1 << ": ";
        cout << res << '/' << n;
        cout << '\n';
    }
    return 0;
}