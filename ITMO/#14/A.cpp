#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> dif(n - 1), arr(n);
    for(int i  = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < n - 1; i++) {
        dif[i] = arr[i + 1] - arr[i] - 1;
    }
    sort(dif.begin(), dif.end());
    for(int i = 0; !dif.empty() && i < k - 1; i++) {
        dif.pop_back();
    }
    int sum = 0;
    for(int i = 0; i < dif.size(); i++) {
        sum += dif[i];
    }
    cout << arr.size() + sum;
    return 0;
}