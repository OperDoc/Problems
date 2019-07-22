#include <bits/stdc++.h>

using namespace std;

long long sum[200010];

long long gSum(int l, int r) {
  return sum[r] - (l == 0 ? 0 : sum[l - 1]);
}

int main() {
  int n, q;
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> sum[i];
    if(i != 0)
      sum[i] += sum[i - 1];
  }
  for(int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    cout << gSum(a - 1, b - 1) << endl;
  }
}
