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
z arr[100010];
int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	z n;
	in >> n;
	fo(i, n) in >> arr[i];
	z now = -1;
	z last = -1;
	z cnt = 1;
	fo(i, n - 1) {
		if(arr[i] == arr[i + 1]){continue;}
		if(last == -1) {last = arr[i] < arr[i + 1] ? 1: 0;}
		if(arr[i] < arr[i + 1]) {
			if(last == 0) {
				cnt ++;
				last = -1;
			}
		} else {
			if(last == 1) {
				cnt ++;
				last = -1;
			} 
		}
    	 
	}
	out << cnt << nl;
}
