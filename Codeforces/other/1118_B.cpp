//https://codeforces.com/problemset/problem/1118/B
#include <iostream>
#include <vector>

using namespace std;

int main(){
   int n;
   cin >> n;
   vector<int> arr(n), sum0(n), sum1(n);
   for(int i = 0; i < n; i++){
      cin >> arr[i];
   }
   sum1[0] = 0;
   sum0[0] = arr[0];
   for(int i = 1; i < n; i++){
      if(i % 2 == 0){
         sum0[i] = arr[i] + sum0[i - 1];
         sum1[i] = sum1[i - 1];
      } else {
         sum0[i] = sum0[i - 1];
         sum1[i] = arr[i] + sum1[i - 1];
      }
   }
   //cout << endl;
   int ans = 0;
   if(sum1[n - 1] == sum0[n - 1] - sum0[0]) ans++;
   if(sum1[n - 2] == sum0[n - 2])ans++;
   for(int i = 1; i < n - 1; i++){
      if(sum0[i - 1] + sum1[n - 1] - sum1[i] == sum1[i - 1] + sum0[n - 1] - sum0[i]) ans++;
      //cout << sum0[i - 1] + sum1[n - 1] - sum1[i] << ' ' << sum1[i - 1] + sum0[n - 1] - sum0[i] << endl;
   }
   cout << ans;
   return 0;
}
