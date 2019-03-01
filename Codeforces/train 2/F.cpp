#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

bool isP[10000010];

void euro(vector<int>& ans) {
    isP[0] = true;
    isP[1] = true;
    for(int i = 2; i < 10000010; i++){
        if(!isP[i]){
            ans.push_back(i);
            for(long long j = (long long)i * i; j < 10000010; j += i) {
                isP[j] = true;
            }
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    vector<int> Ps;
    euro(Ps);
    int T;
    cin >> T;
    cout << fixed;
    cout.precision(4);
    for(int t = 0; t < T; t++) {
        int d, i;
        long long x, cnt = 0;
        cin >> d >> x;
        for(i = 0; i <= d; i++) {
            if(x == cnt) {
                break;
            }
            if(cnt < x) {
                 cnt += ((long long)1<<(d - i));
            } else {
                cnt -= ((long long)1<<(d - i));
            }
        }
        cout << "Case " << t+1 << ": ";
        if(cnt == x) {
            cout << "YES " << i;
        } else {
            cout << "NO";
        }
        cout << '\n';
    }
    return 0;
}