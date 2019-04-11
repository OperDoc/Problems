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

int t[4 * 100000];

int Max(int a, int b){}

int Max(){}

int ch(){}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int n, k, curr = 0, ans = 0;
    in >> n >> k;
    vector<int> arr(n);
    ve<bool> is(k);
    for(int i = 0; i < n; i++) {
        if(!is[arr[i]]) {
            if(curr == k) {
                int ind = Max(0, k);
                
            } else {
                is[arr[i]] = true;
                curr++;
            }
            ans++;
        }
    }

}