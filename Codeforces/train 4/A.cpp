#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define fo(i, n) for(int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define al(a) a.begin(),a.end() 
#define pr pair
#define ve vector
#define fs first
#define sc second
#define in cin
#define out cout 
#define nl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    z n, k, ans = -2, res = -1, a, b;
    in >> k >> n;
    fo(i, n) {cin >> a >> b; if(a > res && b <= k) {res = a; ans = i;}}
    cout << ans + 1 << nl;
}