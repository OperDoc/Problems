#include <bits/stdc++.h>

using namespace std;

int arr[1000010];

const int mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < 6; i++) arr[i] = 1;
  for(int i = 1; i < n; i++)
    for(int j = 1; j < 7 and i - j >= 0; j++)
      arr[i] = (arr[i] +  arr[i - j]) % mod;
  cout << arr[n - 1] << endl;
}
