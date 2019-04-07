#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        int n, a, cnt = 0;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a;
            cnt += (a != 0);
        }
        cout << cnt << '\n';
    }
    return 0;
}