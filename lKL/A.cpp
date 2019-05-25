#include <bits/stdc++.h> 

using namespace std;

typedef long double z;
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

pr<z, z> arr[100010];

bool cmp(pr<z, z> a, pr<z, z> b) {
	return a.fs / a.sc > b.fs / b.sc;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int n;
    in >> n;
    z d, p;
    in >> p >> d;
    fo(i,n){
    	in >> arr[i].fs >> arr[i].sc;
    }
    sort(arr, arr + n, cmp);
    z time = 0;
    fo(i, n){
    	time += arr[i].sc/p;
    	d -= time * arr[i].fs;
    }
    if(d > 0) {
    	out << "NO" << nl;
    } else {
    	out << "YES" << nl;
    }
}