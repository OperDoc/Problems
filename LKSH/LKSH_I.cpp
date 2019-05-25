#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define fo(i, n) for(int i = 0; i < n; ++i)
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

int n;
long long ks0[300010], ks1[300010];

long long F(long long H){
	long long sum = 0;
	fo(i, n){
		sum += abs(ks0[i] - abs(i - n / 2) - H);
	} 
	fo(i, n){
		sum += abs(ks1[i] - abs(i - n / 2) - H);
	}
	return sum;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    in >> n;
    long long a, r = 0;

    for(int i = 0; i < n; i++){
    	in >> a;
    	r = max(r, a);
    	ks0[i] = a;
    }
    for(int i = 0; i < n; i++){
    	in >> a;
    	r = max(r, a);
    	ks1[i] = a;
    }
	long long l = 0, m1, m2; 
    while(r - l > 3){
        m1 = r - (r - l) / 3;
        m2 = l + (r - l) / 3;
        if(F(m1)>F(m2)) r = m1;
        else            l = m2;
    }
    long long res = F(l);
    for(long long i = l; i <= r; i++) {
    	res = min(res, F(i));
    }
    out << res << nl;
}