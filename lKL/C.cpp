#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define fo(i, n) for(int i = 0; i != n; ++i)
#define fe(i, a) for(auto &i : a)
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
#define mod 1000000009
#define p 53

string s, t;

long long hashS[500010], hashT[1010], pows[500010];

struct cmpT {
    bool operator() (const pr<z, z> &a, const pr<z, z> &b) const {
        for(z i = 0; i < min(a.sc - a.fs, b.sc - b.fs); i++) {
        	if(t[a.fs + i] != t[b.fs + i]) return t[a.fs + i] < t[b.fs + i]; 
        }
        return a.sc - a.fs < b.sc - b.fs;
    }
};
struct cmpS {
    bool operator() (const pr<z, z> &a, const pr<z, z> &b) const {
        for(z i = 0; i < min(a.sc - a.fs, b.sc - b.fs); i++) {
        	if(s[a.fs + i] != s[b.fs + i]) return s[a.fs + i] < s[b.fs + i]; 
        }
        return a.sc - a.fs < b.sc - b.fs;
    }
};

char atS(pr<z, z> &a, z i){
	return s[a.fs + i];
}

char atT(pr<z, z> &a, z i){
	return t[a.fs + i]; 
}

long long getHS(pr<z, z> &a, z i) {
	z l = a.fs;
	z r = a.fs + i;
	long long L = l == 0 ? 0 : hashS[l - 1] * pows[r - l + 1] % mod;
    return (hashS[r] + mod - L) % mod;
}

long long getHT(pr<z, z> &a, z i) {
	z l = a.fs;
	z r = a.fs + i;
	long long L = l == 0 ? 0 : hashT[l - 1] * pows[r - l + 1] % mod;
    return (hashT[r] + mod - L) % mod;
}

z lspS(pr<z, z> &a, pr<z, z> &b) {
	z l = 0, r = min(a.sc - a.fs, b.sc - b.fs);
	while(r - l > 1) {
		z m = (l + r) / 2;
		if(getHS(a, m) == getHS(b, m)) {
			l = m;
		} else {
			r = m;
		}
	}
	return r;
}

z lspT(pr<z, z> &a, pr<z, z> &b) {
	z l = 0, r = min(a.sc - a.fs, b.sc - b.fs);
	while(r - l > 1) {
		z m = (l + r) / 2;
		if(getHT(a, m) == getHT(b, m)) {
			l = m;
		} else {
			r = m;
		}
	}
	return r;
}

z lspST(pr<z, z> &a, pr<z, z> &b){
	z l = 0, r = min(a.sc - a.fs, b.sc - b.fs);
	while(r - l > 1) {
		z m = (l + r) / 2;
		if(getHS(a, m) == getHT(b, m)) {
			l = m;
		} else {
			r = m;
		}
	}
	return r;
}

bool lessS(pr<z, z> &a, pr<z, z> &b) {
	z x = lspS(a, b);
	return atS(a, x) < atS(b, x);
}

bool lessT(pr<z, z> &a, pr<z, z> &b) {
	z x = lspT(a, b);
	return atT(a, x) < atT(b, x);
}

bool lessST(pr<z, z> &a, pr<z, z> &b){
	z x = lspST(a, b);
	return atS(a, x) < atT(b, x); 
}

inline string mSliseS(z i, z j){
	string ans(j - i, 'a');
	for(int ind = 0; ind < j - i; ind++) {
		ans[ind] = s[i + ind];
	}
	return ans;
}

inline void mSliseT(z i, z j, pr<ve<long long, z>> ans){
	ans.sc = j - i;
	ans.fs = ve<long long>((j - i + 31) / 32);
	for(int ind = 0; ind < j - i; ind++) {
		ans[ind] = t[i + ind];
	}
	return ans;
}

int main() {
	//ios_base::sync_with_stdio(0);
    //cin.tie(0), cout.tie(0);
    z n, m;
    in >> n >> m;
    in >> s >> t;
    //for (int i = 0; i < 500010; ++i) pows[i] = i == 0 ? 1 : pows[i - 1] * p % mod;
    //for (int i = 0; i < n; ++i) hashS[i] = i == 0 ? s[i] : (p * hashS[i - 1] + s[i]) % mod;
    //for (int i = 0; i < m; ++i) hashT[i] = i == 0 ? t[i] : (p * hashT[i - 1] + t[i]) % mod;
	set<string> subT;
	for(z len = 1; len <= m; ++len) {
		for(z i = 0; i + len <= m; ++i) {
			subT.insert(mSliseT(i, i + len));
		}
	}
	bool isAns = false;
	z ind = -1;
	for(z len = 1; len <= n; ++len) {
		for(z i = 0; i + len <= n; ++i) {
			isAns = subT.end() == subT.find(mSliseS(i, i + len));
			if(isAns) {
				out << mSliseS(i, i + len) << nl; 
				return 0;
			}
		}
	}
	out << "NONE" << nl;
	//sort(al(subT), lessT);
	//sort(al(subS), lessS);
}