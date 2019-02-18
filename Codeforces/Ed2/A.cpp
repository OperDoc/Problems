#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
   int n;
   cin >> n;
   vector<int> arr(n);
   for(int i = 0; i < n; i++) cin >> arr[i];
   int m = *max_element(arr.begin(), arr.end());
   int ans = 0, cnt = 0;
   for(int i = 0; i < n; i++){
      if(arr[i] == m){
         ans++;
      }else{
         ans = 0;
      }
      cnt = max(ans, cnt);
   }
   cout << cnt;
   return 0;
}
