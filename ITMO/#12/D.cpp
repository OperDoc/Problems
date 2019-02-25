#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long arr[100010][2];

int main() {
   long long ans = 0;
   int n;
   cin >> n;
   for(int i = 0; i < n; i++){
      cin >> arr[i][0] >> arr[i][1];
   }
   for(int i = n - 1; i >= 0; i--) {
      if((arr[i][0] + ans) % arr[i][1] != 0)
         ans += arr[i][1] - (arr[i][0] + ans) % arr[i][1];
   }
   cout << ans;
   return 0;
}
