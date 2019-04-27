#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define fo(i, n) for(int i = 0; i < n; ++i)
#define fe(i, a) for(auto &i : a)
#define ff(i, a) for(unsigned int i = 0; i < a.size(); ++i)
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
	string s;
	in >> s;
	z l = -1, r = -1;
	ff(i,s){
		if(i + 2 < s.size() and s[i + 2] == s[i]){
			l = i + 1;
			r = i + 3;
			break;
		}
		if(i + 1 < s.size() and s[i + 1] == s[i]){
			l = i + 1;
			r = i + 2;
			break;	
		}
	}	
	out << l << " " << r << nl;
}
