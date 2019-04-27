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

long long Mround(long double k){
    return floor((long double)k + 0.5);
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int n;
    in >> n;
    priority_queue<long long> T, D;
    fo(i, n) {
        char a;
        long long b;
        in >> a >> b;
        if(a == 'T') {
            T.push(-b);
        } else {
            D.push(-b);
        }
    }
    D.push(-1000);
    long long v = 1;
    long double lastT = 0, lastD = 0;
    while(!(T.empty() && D.empty())) {
        long double currD = D.empty() ? -1 : -D.top();
        long double currT = T.empty() ? -1 : -T.top();
        if(currD == -1) {
            lastD += (long double)(currT - lastT) / v; 
            lastT = currT;
            T.pop();
        } else if (currT == -1) {
            lastT += (long double)v * (currD - lastD);
            lastD = currD;
            D.pop();
        } else if (v * (currD - lastD) > currT - lastT) {
            lastD += (long double)(currT - lastT) / v; 
            lastT = currT;
            T.pop();
        } else {
            lastT += (long double) v * (currD - lastD);
            lastD = currD;
            D.pop();
        }
        v++;
    }
    out << Mround(lastT) << nl;
}