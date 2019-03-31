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

#define N 100000

z arr[N];

z input(){ z a; in >> a;return a;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    z n = input(), max = 0, cnt;
    fo(i, n) arr[input()]++;
    fo(i, N) {
        if(arr[i] == arr[max])cnt++;
        if(arr[i] > arr[max]){
            max = i; 
            cnt = 0;
        }
    }
    if(cnt) {
        out << -1 << nl;
    } else {
        out << max << nl;
    }
}