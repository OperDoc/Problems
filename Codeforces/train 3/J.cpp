#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define in cin
#define out cout
#define ffor(i, n) for(int i = 0; i < n; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char a, b, c, d;
    in >> a >> b >> c >> d;
    z A = a - 'a' + 1, B = b - '0', C = c - 'a' + 1, D = d - '0';
    if((A + B) % 2 != (C + D) % 2) {
        out << "NO\n";
        return 0;
    }
    if(A == C && B == D) {
        cout << 0 << '\n';
        return 0;
    }
    if(abs(A - C) == abs(B - D)) {
        out << 1 << '\n';
        return 0;
    }
    out << 2 << '\n';
}