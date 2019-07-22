#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  set<int> mp;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    mp.insert(a);
  }
  cout << mp.size() << endl;
}
