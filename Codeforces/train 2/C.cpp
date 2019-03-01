#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;
    const long double PI = atan2(0, -1);
    cout << fixed;
    cout.precision(4);
    for(int t = 0; t < T; t++) {
        long double r;
        cin >> r;
        cout << "Case " << t+1 << ": " << r * r / 4 << '\n';
    }
    return 0;
}