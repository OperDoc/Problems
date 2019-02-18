#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
   int n, m, k;
   cin >> n >> k >> m;
   vector<int> arr(n);
   for(int i = 0; i < n; i++)cin >> arr[i];
   sort(arr.rbegin(), arr.rend());
   long long max1 = arr[0], max2 = arr[1];
   if(m < k){
      long long colv = k / (m + 1), cnt = max1 * m + max2;
      cout << colv * cnt + k % (m + 1) * max1;
   } else {
      cout << max1 * m;
   }
   return 0;
}
