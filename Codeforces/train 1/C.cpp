#include <iostream>
#include <vector>

using namespace std;

int tr[400000];
int n;
#define M (l + r)/2
int ch(int ind, int val, int i = 0, int l = 0, int r = n) {
    if(r - l == 1) return tr[i] = val;
    if(ind < M) return tr[i] = ch(ind, val, 2 * i, l, M) + tr[2 * i + 1];
    return tr[i] = tr[2 * i] + ch(ind, val, 2 * i + 1, M, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    cout.precision(20);
    for(int t = 0; t < T; t++) {
        cin >> n;
        vector<int> a(n), b(n), z(n);
        vector<bool> is(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            z[a[i]] = i;
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            b[i]--;
        }
        int ans = 0;
        for(int i = 0; i < 400000; i++) tr[i] = 0;
        for(int l = 0, r = 0; l < n; l++) {
            while(r < n && r < z[b[l]]) {
                ch(a[r], 1);
                r++;
            }
            ch(b[l], 0);
            ans += tr[0];
            r++;
        }
        cout << ans << endl;
    }
    return 0;
}