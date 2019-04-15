#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define fo(i, n) for(int i = 0; i < n; i++)
#define fe(i, a) for(auto &i : a)
#define ff(i, a) for(int i = 0; i < a.size(); i++)
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

void getV(long long n, ve<z>& Ans) {
	while(n != 0) {
		Ans.pb(n % 2);
		n /= 2;
	}
	reverse(al(Ans));
}

long long ans(long long n) {
	ve<z> res;
	getV(n, res);
	long long ans = n != 1;
	for(int i = 1; i < (res.size() + 1) / 2; i++) {
		ans += (1ll<<(i - 1));
	}
	for(int i = 1; i < (res.size()) / 2; i++) {
		ans += (1ll<<(i - 1));
	}
	for(int i = 1; i < (res.size() + 1) / 2; i++) {
		if(res[i] == 1) {
			ans += (1ll<<((res.size() + 1) / 2 - i - 1));
		}
	}
	ve<z> pl(res.size());
	for(int i = 0; i < (res.size() + 1) / 2; i++) {
		pl[i] = res[i];
		pl[res.size() - i - 1] = res[i];
	}
	long long is = 0;
	for(int i = 0; i < res.size(); i++) {
		if(res[i] < pl[i]) {
			is = 1;
			break;
		}
		if(res[i] > pl[i]) {
			break;
		}
	}
	return ans + 1ll - is;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    long long L, R;
    in >> L >> R;
    out << ans(R) - ans(L - 1) << nl;
    return 0;
}