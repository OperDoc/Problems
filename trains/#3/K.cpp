#include <bits/stdc++.h> 
using namespace std;

typedef int z;
#define ffor(i, n) for(int i = 0; i < n; i++)
#define mP make_pair
#define pB push_back
#define all(a) a.begin(),a.end() 
#define pr pair
#define vec vector
#define fs first
#define sc second 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    z n, ans = 0, b;
    cin >> n;
    vec<z> a;
    set<z> s;
    ffor(i, n) {
        cin >> b;
        if(s.insert(b).sc) {
            a.push_back(b);
        }
    }
    sort(all(a));
    for(int l = 0, r = 0; l < a.size(); l++) {
        while(r < a.size() && a[r] < a[l] + n) r++;
        ans = max(ans, r - l);
    }
    cout << n - ans;
}