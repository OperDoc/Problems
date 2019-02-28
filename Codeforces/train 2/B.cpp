#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long double sqr(long double a) {
    return a * a;
}

long double trdrt(long double a) {
    long double l = 0, r = 1e6;
    for(int i = 0; i < 100; i++){
        long double m = (l + r) / 2;
        if(m * m * m < a) {
            l = m;
        } else {
            r = m;
        }
    }
    return r;
}

int main() {
    int T;
    cin >> T;
    const long double PI = atan2(0, -1);
    cout << fixed;
    cout.precision(4);
    for(int t = 0; t < T; t++) {
        long double m, d;
        cin >> m >> d;
        cout << "Case " << t+1 << ": " << 4 * PI * sqr(trdrt(3 * m / (4 * d * PI))) << '\n';
    }
    return 0;
}
