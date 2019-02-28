#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        if(n + 1 <= 2 * (a + b + c + d)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}