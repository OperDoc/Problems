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

int arr[300010], ord[300010];

int main() {
  //ios_base::sync_with_stdio(0);
  //cin.tie(0); cout.tie(0);
  int n;
  in >> n;
  for(int i = 0; i < n; i++) {in >> arr[i]; ord[i] = i;}
  sort(ord, ord + n, [&](int i, int j){return arr[i] < arr[j];});
  for(int i = 0; i < n; i++) out << ord[i] + 1 << ' ';
  out << nl;
}
