#include <iostream>
#include <vector>
#include <algorithm>
#include <priority_queue>

using namespace std;

int main() {
   int n, x;
   cin >> n;
   vector<int> ks(n), as(n), bs(n);
   for(int i = 0; i < n; i++) cin >> ks[i];
   for(int i = 0; i < n; i++) cin >> as[i];
   for(int i = 0; i < n; i++) cin >> bs[i];
   cin >> x;
   return 0;
}
