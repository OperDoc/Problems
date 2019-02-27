#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    cout.precision(20);
    for(int t = 0; t < T; t++) {
        int a, b;
        double c;
        cin >> a >> b >> c;
        cout << c * c / 2 << '\n';
    }
    return 0;
}