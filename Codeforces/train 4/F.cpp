#include <bits/stdc++.h> 

using namespace std;

typedef int z;
#define fo(i, n) for(int i = 0; i < n; i++)
#define fe(i, a) for(auto &i : a)
#define ff(i, a) for(int i = 0; i < a.size(); i++)
#define mp make_pair
#define pb push_back
#define al(a) a.begin(),a.end() 
#define pr pair
#define ve vector
#define fs first
#define sc second
#define in cin
#define out cout 
#define nl '\n'

z n, m;
ve<ve<char>> nm;

char go(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m) return 'x';
    if(nm[i][j] != '0') return nm[i][j];
    return nm[i][j] = ((go(i + 1, j) == '2') || (go(i, j + 1) == '2') || (go(i + 1, j + 1) == '2')) ? '1' : '2';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    in >> n >> m;
    nm.resize(n, ve<char>(m));
    fo(i, n) {
        fo(j, m) {
            in >> nm[i][j];
        }
    }
    cout << go(0, 0) << nl;
    fo(i, n) {
        fo(j, m) {
            out << nm[i][j];
        }
        out << nl;
    }
}
