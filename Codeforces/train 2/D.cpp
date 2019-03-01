#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    const long double PI = atan2(0, -1);
    cout << fixed;
    cout.precision(4);
    for(int t = 0; t < T; t++) {
        string s;
        cin >> s;
        cout << "Case " << t+1 << ": ";
        for(int i = 0; i < s.size(); i++) {
            cout << s[i];
        }
        for(int i = s.size() - 2; i >= 0; i--) {
            cout << s[i];
        }
        cout << '\n';
    }
    return 0;
}
