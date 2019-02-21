#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N 10010

vector<int> G[N];

int main(){
   int n;
   cin >> n;
   for (int i = 0, a, b; i < n - 1; i++) {
      cin >> a >> b;
      G[a - 1].push_back(b - 1);
      G[b - 1].push_back(a - 1);
   }
   long long ans = 0;
   for(int i = 0; i < n; i++){
      ans += G[i].size() *( G[i].size() - 1);
   }
   cout << ans / 2 << '\n';
   return 0;
}
