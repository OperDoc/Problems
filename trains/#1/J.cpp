#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt[40010];

int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        int n, a;
        cin >> n;
        for(int i = 0; i < 40010; i++) {
            cnt[i] = 0;
        }
        for(int i = 0; i < n; i++) {
            cin >> a;
            cnt[a]++;
        }
        int mmax = 0;
        for(int i = 0; i < 40010; i++) {
            mmax = max(cnt[i] + cnt[i + 1], mmax);
        }
        cout << mmax << '\n';
    }
    return 0;
}