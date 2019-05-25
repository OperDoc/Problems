#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define fo(i, n) for(int i = 0; i != n; ++i)
#define fe(i, a) for(auto &i : a)
#define ff(i, a) for(int i = 0; i != a.size(); ++i)
#define al(a) a.begin(),a.end()
#define ve vector
#define pb push_back
#define mp make_pair
#define pr pair
#define fs first
#define sc second
#define in cin
#define out cout 
#define nl '\n'
#define inv(a) bin_pow(a, 1e9 + 5)

z arr[100'001], Max[100'001], val[100'001];
bool is[100'001];

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    z n, t;
    in >> n >> t;
    for(z i = 0; i < n; i++) {
    	in >> arr[i];
    }
    Max[n - 1] = n - 1;
    for(z i = 1; i < n; i++) {
    	Max[n - i - 1] = arr[n - i - 1] > arr[Max[n - i]] ? n - i - 1 : Max[n - i];
    }
    for(z i = 0; i < n; i++) {
    	val[i] = arr[Max[i]] - arr[i]; 
    }
    z mx = *max_element(val, val + n);
    z ans = 0;
    fo(i, n) {
    	if(val[i] == mx && !is[Max[i]]) {
    		ans++;
    		is[Max[i]] = true;
    	}
    }
    out << ans << nl;
}
