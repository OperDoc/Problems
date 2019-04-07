#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        map<int, int> m;
        int n, q, ans = 0, a, b, c;
        cin >> n >> q;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            if(arr[i] != 0)m[arr[i]]++;
            if(m[arr[i]] == 1) {
                ans++;
            }
        }
        for(int i = 0; i < q; i++) {
            cin >> a;
            if(a == 2) {
                cout << ans << '\n';
            } else {
                cin >> b >> c;
                if(c != arr[b - 1]) {
                    m[arr[b - 1]]--;
                    if(arr[b - 1] != 0 && m[arr[b - 1]] == 0) {
                        ans--;
                    }
                    arr[b - 1] = c;
                    m[arr[b - 1]]++;
                    if(arr[b - 1] != 0 && m[arr[b - 1]] == 1) {
                        ans++;
                    }
                }
            }
        }
    }
    return 0;
}