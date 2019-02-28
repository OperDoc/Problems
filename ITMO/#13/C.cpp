#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long fib(long long a, long long b, long long n) {
    vector<long long> ans(max(n + 1, (long long)2));
    ans[0] = a;
    ans[1] = b;
    for(int i = 2; i < n; i++) {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    return ans[n - 1];
}

int main(){
    long long k, x, n, m;
    cin >> k >> x >> n >> m;
    long long ans = 0;
    int ii = 0, jj = 0;
    for(int i = 0; i <= n / 2; i++) {
        for(int j = 0; j <= m / 2; j++) {
            ans = fib(i, j, k);
            if(ans == x) {
                ii = i;
                jj = j;
                break;
            }
        }
        if(ans == x) {
            break;
        }
    }
    if(ans != x) {
        cout << "Happy new year!";
        return 0;
    }
    int i = 0, j = 0;
    for(; i < 2 * ii; i += 2) {
        cout << "AC";
    }
    for(; i < n; i += 1) {
        cout << "B";
    }
    cout << endl;
    for(; j < 2 * jj; j += 2) {
        cout << "AC";
    }
    for(; j < m; j += 1) {
        cout << "B";
    }
    return 0;
}