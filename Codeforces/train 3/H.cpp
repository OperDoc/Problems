#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define ffor(i, n) for(int i = 0; i < n; i++)
#define mP make_pair
#define pB push_back
#define all(a) a.begin(),a.end() 
#define pr pair
#define vec vector

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    z n;
    cin >> n;
    vec<pr<z, z>> eves;
    ffor(i, n) {
        z a, b, c, d;
        cin >> a >> b >> c >> d;
        a = a * 60 + b;
        c = c * 60 + d;
        if(c < a) {
            eves.pB(mP(0, 1));
            eves.pB(mP(c + 24 * 60, -1));
        }
        eves.pB(mP(a, 1));
        eves.pB(mP(c, -1));
    }
    sort(all(eves));
    z ans = 0, cnt = 0;
    for(auto &i : eves) {
        cnt += i.second;
        ans = max(ans, cnt);
    }
    cout << ans;
}