#include <iostream>
#include <vector>

using namespace std;

int intSqrt(int a) {
    int l = 1, r = 1e4;
    while(r - l > 1) {
        int m = (r + l) / 2;
        if(m * m > a) {
            r = m;
        } else {
            l = m;
        }
    }
    return l;
}

int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        int a;
        cin >> a;
        cout << intSqrt(a / 6) << '\n';
    }
    return 0;
}