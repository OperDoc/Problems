#include <bits/stdc++.h>

using namespace std;

int arr[200010], ord[200010];

int indFind(int x, int n) {
  int l = 0, r = n;
  while(r - l > 1) {
    int m = (l + r) / 2;
    if(arr[ord[m]] > x) r = m;
    else l = m;
  }
  return ord[l];
}

int main() {
  int n, x;
  cin >> n >> x;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    ord[i] = i;
  }
  sort(ord, ord + n, [&](int i, int j) {return arr[i] < arr[j];});
  for(int i = 0; i < n; i++) {
    int ind = indFind(x - arr[i], n);
    //cout << arr[ind] << endl;
    if(ind != i and arr[ind] + arr[i] == x) {
      cout << i + 1 << ' ' << ind + 1 << endl;
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;
}
