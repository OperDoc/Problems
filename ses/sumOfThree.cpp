#include <bits/stdc++.h>

using namespace std;

int arr[5010], ord[5010];

int findInd(int x, int n) {
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
    for(int j = i + 1; j < n; j++) {
      int k = findInd(x - arr[i] - arr[j], n);
      if(x - arr[k] == arr[i] + arr[j] and k != i and k != j) {
	cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
	return 0;
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
}
