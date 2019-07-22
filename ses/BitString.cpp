#include <bits/stdc++.h>
 
using namespace std;
 
#define mod 1000000007
 
long long mPow(int n) {
  return n == 0 ? 1 : (2 * mPow(n - 1)) % mod;
}
 
int main() {
  int n;
  cin >> n;
  cout << mPow(n) << endl;
}
