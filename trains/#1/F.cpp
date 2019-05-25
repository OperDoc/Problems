#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        int n, m, s, e, mm, hh, total, sum = 0;
        char c;
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> hh >> c >> mm;
            s = hh * 60 + mm;
            cin >> hh >> c >> mm;
            e = hh * 60 + mm;
            total = e - s;
            if(e < s) {
                total = 24 * 60 - total;
            }
            sum += total;
        }
        if(m * 60 <= sum) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}