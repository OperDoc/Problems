#include <bits/stdc++.h>

using namespace std;

int cnt[10];

void apd(int i) {
  while(i > 0) {
    cnt[i % 10]++;
    i /= 10;
  }
}

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    apd(i);
  }
  for(int i = 0; i < 9; i++) {
    cout << cnt[i] << endl;
  }
}
