#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[26], ans[26];

int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    for(int i = 0; i < s.size(); i++) {
        arr[s[i] - 'a']++;
    }
    int cnt = 0;
    for(int i = 0; i < 26; i++) {
        cnt += (arr[i] != 0);
    }
    if(cnt > n) {
        cout << -1;
        return 0;
    }
    for(int i = 0; i < 26; i++) {
        ans[i] = (arr[i] != 0);
    }
    int allredy = n - cnt;
    //cout << allredy << endl;
    int ii, mmax;
    while(allredy > 0) {
        mmax = 0, ii = 0;
        for(int i = 0; i < 26; i++) {
            if(ans[i] && mmax < (arr[i] + ans[i] - 1)/ ans[i]) {
                mmax = (arr[i] + ans[i] - 1)/ ans[i];
                ii = i;
            }
        }
        ans[ii] += 1;
        allredy--;
    }
    mmax = 0;
    for(int i = 0; i < 26; i++) {
        if(ans[i] && mmax < (arr[i] + ans[i] - 1)/ ans[i]) {
            mmax = (arr[i] + ans[i] - 1)/ ans[i];
            ii = i;
        }
    }
    cout << mmax << '\n';
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < ans[i]; j++) {
            cout << (char)('a' + i);
        }
    }
    return 0;
}