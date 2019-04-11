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
#define mod 1000000007

struct otr {
	long long i, j, l;
	otr(long long a, long long b, long long c):i(a),j(b),l(c){}
	otr(){}
	bool operator < (const otr &a) const {
	return (l / 2) < (a.l / 2) || ((l / 2) == (a.l / 2) && i > a.i);
	}
};

int n;

priority_queue<otr> q;

long long Add() {
	otr cnt = q.top(); q.pop();
	otr nel = otr(cnt.i, cnt.i + cnt.l / 2, cnt.l / 2);
	otr ner = otr(cnt.i + cnt.l / 2, cnt.j, abs(cnt.j - (cnt.i + cnt.l / 2)));
	if(nel.i > 0 && nel.j > 0 && nel.i <= n && nel.j <= n && nel.l > 0)q.push(nel);
	if(ner.i > 0 && ner.j > 0 && ner.i <= n && ner.j <= n && ner.l > 0)q.push(ner);
	return cnt.i + cnt.l / 2;
}


int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int m;
	in >> n >> m;
	ve<long long> ans(m);
	in >> ans[0];
	otr stl, str;
	if(ans[0] != 1 && ans[0] != n) {
		stl = otr(-ans[0] + 2, ans[0], 2 * ans[0] - 2);
		str = otr(ans[0], -ans[0] + 2 * n, 2 * (n - ans[0]));
		q.push(stl);
		q.push(str);
	} else if(ans[0] == 1) {
		stl = otr(ans[0], 2 * n - 1, 2 * n - 2);
		q.push(stl);
	} else if(ans[0] == n) {
		stl = otr(-n + 2, ans[0], 2 * n - 2);
		q.push(stl);
	}
	for(int i = 1; i < m; i++) {
		ans[i] = Add();
	}
	for(int i = 0; i < m; i++) {
		if(ans[i] < 0) while(true){
			ans[i] = 0;
		}
		
	}
	long long res = 0;
	for(int i = 0; i < m; i++) {
		res += (ans[i] * (i + 1)) % mod;
		res %= mod;
	}
	out << res << nl;
	//for(int i = 0; i < m; i++) {
	//	out << ans[i] << ' ';
	//}
	//out << nl;
}