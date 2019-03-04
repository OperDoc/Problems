#include <bits/stdc++.h> 

using namespace std;

typedef long long z;
#define in cin

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    z n;
    in >> n;
    if(n == 2) cout << 2;
    else cout << (n % 4 == 3 || n % 4 == 0 ? 0 : 1);
}