#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n), b(n); 
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    b[0] = arr[0];
    for(int i = 1; i < n; i++) {
        b[i].first = max(b[i - 1].first + 1, arr[i].first);
        b[i].second = arr[i].second;
    }
    for(int i = 0; i < n; i++) {
        ans[b[i].second] = b[i].first;
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}