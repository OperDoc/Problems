#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

int main() {
   int n;
   cin >> n;
   n++;
   long long a;
   cin >> a;
   vector<pair<long long, long long>> arr(n);
   arr[0] = {0, -1};
   vector<int> res(n);
   for(int i = 1; i < n; i++){
      cin >> arr[i].first;
      arr[i].second = i;
   }
   sort(arr.begin(), arr.end());
   for(int i = 0; i < n; i++){
      int l = 0, r = n;
      while(r - l > 1){
         int m = (l + r) / 2;
         if(arr[i].first * arr[m].first > a || (arr[i].first != 0 && arr[m].first != 0 && arr[i].first > LLONG_MAX / arr[m].first)){
            r = m;
         } else{
            l = m;
         }
      }
      res[i] = l;
      if(l == i){res[i]--;}
   }
   long long ans = 0, ind = -1;
   for(int i = 0; i < n; i++){
      if((long long) arr[i].first * arr[res[i]].first > ans) {
         ind = i;
         ans = (long long) arr[i].first * arr[res[i]].first;
      }
   }
   if(ans != 0)
      cout << ans << '\n' << arr[ind].second << ' ' << arr[res[ind]].second;
   else
      cout << 0;
   return 0;
}
