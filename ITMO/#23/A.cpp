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

int main() {
  //ios_base::sync_with_stdio(0);
  //cin.tie(0), cout.tie(0);
  freopen("conquest.in", "r", stdin);
  freopen("conquest.out","w",stdout);
  z n;
  long long ans=0;
  in >> n;
  ve<z> arr(n);
  fo(i,n){
    in >> arr[i];
    if(i!=0)arr[i]=min(arr[i],arr[i-1]);
    if(i!=n-1)ans+=arr[i];
  }
  out << ans << nl;
}
