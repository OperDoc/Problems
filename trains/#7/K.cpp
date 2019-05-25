#include <bits/stdc++.h>

using namespace std;

typedef int z;
#define fo(i, n) for(int i = 0; i < n; i++)
#define fl(i, n) for(int i = 0; i < n.size(); i++)
#define fe(i, n) for(auto &i : n)
#define al(n) n.begin(),n.end()
#define ve vector
#define pb push_back
#define mp make_pair
#define pr pair
#define fs first
#define sc second
#define in cin
#define out cout
#define nl '\n'

int main(){
    z n;
    in >> n;
    map<string, int> cnt, mmax;
    ve< pr< pr< string, string >, int > > arr;
    fo(i, n) {
        string s, s1, s2;
        in >> s >> s1 >> s2 >> s;
        arr.pb(mp(mp(s1, s), -1));
        arr.pb(mp(mp(s2, s), 1));
    }
    sort(al(arr));
    fe(i, arr) {
        cnt[i.fs.sc] -= i.sc;
        if(cnt[i.fs.sc] > mmax[i.fs.sc]) mmax[i.fs.sc] = cnt[i.fs.sc];
    }
    ve<pr<int, string>> ans;
    fe(i, mmax) {
        ans.pb(mp(i.sc, i.fs));
    }
    ve<z> ord(ans.size());
    fl(i, ans) ord[i] = i;
    sort(al(ord), [&](int i, int j){return ans[i].fs > ans[j].fs || (ans[i].fs == ans[j].fs && ans[i].sc < ans[j].sc);});
    fe(i, ord){
        out << ans[i].sc << ' ' << ans[i].fs << nl;
    }
}