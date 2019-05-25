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

long long arr[100000];

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    long long n, m, ans = 0;
    in >> n >> m;
    fo(i, n) {
    	in >> arr[i];
    }
    fo(i, n - 1) {
    	if(arr[i] + arr[i + 1] > m) {
    		ans += min(arr[i + 1], arr[i] + arr[i + 1] - m);
    		arr[i + 1] -= min(arr[i + 1], arr[i] + arr[i + 1] - m);
    		if(arr[i] > m) {
    			ans += arr[i] - m;
    			arr[i] = m; 
    		}
    	}
    }
    out << ans << nl;
}
