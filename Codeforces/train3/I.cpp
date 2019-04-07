#include <bits/stdc++.h> 

using namespace std;

typedef long long z;
#define in cin
#define out cout
#define ffor(i, n) for(int i = 0; i < n; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    z n, m, ans = 0, a;
    in >> n >> m;
    ffor(i, n) {
        in >> a;
        ans += (a + m - 1) / m;
    }
    out << ans * m;
}