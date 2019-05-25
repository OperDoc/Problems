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
const long long mod = 1e9 + 7;

long long mmod(long long a){
	return ((a % mod) + mod) % mod;
}
ve<z> cnt;
int f[1000010];
int used[1000010];
long long n, k;

int mCount(int v, int from) {
	used[v] = 3;
	if (f[v] == from) return 1;
	return mCount(f[v], from) + 1;
}

int mcount(int v, int from) {
	int ans = 1;
	while(f[v] != from) {
		used[v] = -1;
		ans++;
		v = f[v];
	}
	used[v] = -1;
	return ans;
}


void dfs(int v, int t){
	while(f[v] != v && used[f[v]] == 0) {
		used[v] = t;
		v = f[v];
	}
	if(f[v] != v && used[f[v]] == t) {
		cnt.pb(mcount(f[v], f[v]));
	}
}

void dfs(int v) {
	used[v] = 1;
	if(f[v] != v && used[f[v]] == 0) dfs(f[v]);
	if(f[v] != v && used[f[v]] == 1) cnt.pb(mCount(f[v], f[v])); 
	if(used[v] == 1)used[v] = 2;
}

long long mPow(long long a, z N){
	if(N == 0) return 1;
	if(N % 2 == 1) return mmod(a * mPow(a, N - 1));
	long long ans = mPow(a, N / 2);
	return mmod(ans * ans);
}

long long C(int N) {
	if(N % 2 == 0) {
		return mmod(mPow(mmod(k - 1), N) + (k - 1));
	}
	return mmod(mPow(mmod(k - 1), N) - (k - 1)); 
}


int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    in >> n >> k;
    fo(i, n) {
    	in >> f[i];
    	f[i]--;
    }
    for(int i = 0; i < n; i++) {
    	if(used[i] == 0) {
    		dfs(i, i + 1);
    	}
    }
    long long ans = 1;
    for(int i = 0; i < cnt.size(); i++) {
    	ans = mmod(ans * C(cnt[i]));
    }
    for(int i = 0; i < n; i++) {
    	if(used[i] != -1) {
    		if(f[i] == i) {
    			ans = mmod(ans * k);
    		} else {
    			ans = mmod(ans * (k - 1));
    		}
    	}
    }
    out << ans << nl;
}