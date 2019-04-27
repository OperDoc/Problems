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

z a[100000];

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);            
	//cout.tie(0);
	z n;
	in >> n;
	fo(i, n){
		in >> a[i];		
	}
	sort(a, a + n);
	z l = 0;
	long long sum = 0;
	fo(i, n){
		i = l;
		sum += a[l];
		l++;
		while(a[l] <= sum * 2) {
			sum += a[l];
			l++;
			if (l >= n){ 
				break;	
			}
		}
		if(l >= n){
			l = i;
			break;
		}
	}			
	out << n - l << nl;		
}