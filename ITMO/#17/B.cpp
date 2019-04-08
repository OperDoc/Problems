#include <bits/stdc++.h> 

using namespace std;

typedef double z;
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

int make(string &s, char c) {
	bool is = true;
	for(int i = 0; i < s.size(); i++) if(s[i] != c) is = false;
	if(is) return 0;
	string t(s.size() - 1, 'a');
	for(int i = 0; i < s.size() - 1; i++) {
		if(s[i + 1] == c) {
			t[i] = c;
		} else {
			t[i] = s[i];
		}
	}
	return make(t, c) + 1;
}

double dist(pr<z, z> a, pr<z, z> b) {
	z c = a.fs - b.fs;
	z d = a.sc - b.sc;
	return sqrt(c * c + d * d);
}

pr<z, z> sub(pr<z, z> a, pr<z, z> b) {
	return mp(a.fs - b.fs, a.sc - b.sc);
}

double cp(pr<z, z> a, pr<z, z> b) {
	return a.fs * b.sc - a.sc * b.fs;
}

double dp(pr<z, z> a, pr<z, z> b) {
	return a.fs * b.fs + a.sc * b.sc;
}

double dist(pr<z, z> o, pr<z, z> a, pr<z, z> b) {
	if(dp(sub(o, a), sub(b, a)) < 0) return dist(o, a);
	if(dp(sub(o, b), sub(a, b)) < 0) return dist(o, b);
	return abs(cp(sub(a, o), sub(b, o))) / dist(a, b);
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int n;
    in >> n;
    pr<z, z> P, a, b;
    in >> P.fs >> P.sc;
    ve<pr<z, z>> Ps;
    double Min, Max;
    fo(i, n) {
    	in >> a.fs >> a.sc;
    	Ps.pb(a);
    	if(dist(P, a) < Min || i == 0) Min = dist(P, a);
    	if(dist(P, a) > Max || i == 0) Max = dist(P, a);
    }
    fo(i, n) {
    	a = Ps[i];
    	b = Ps[(i + 1) % n];
    	double dst = dist(P, a, b);
    	if(dst < Min) Min = dst;
    }
    double PI = 3.14159265359;
    double ans = PI * (Max * Max - Min * Min);
    out.precision(20);
    out << ans << nl;
}


