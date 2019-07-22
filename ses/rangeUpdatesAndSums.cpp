#include <bits/stdc++.h>

using namespace std;

const int k = 500;
long long arr[k * k], madd[k], st[k];
long long sum[k];

void upd(int a) {
  for(int i = k * a; i < a * k + k; i++)
    if(st[a] != 0)
      arr[i] = st[a] + madd[a];
    else
      arr[i] += madd[a];
  madd[a] = 0;
  st[a] = 0;
}

void inc(int a, int b, int x) {
  upd(a / k);
  upd(b / k);
  if(b - a <= k) { 
    for(; a <= b; a++) {
      sum[a / k] += x;
      arr[a] += x;

    }
    return;
  }
  for(; a % k != 0; a++) {
    arr[a] += x;
    sum[a / k] += x;
  }
  for(; a / k != b / k; a += k) {
    madd[a / k] += x;
    sum[a / k] += x * k;
  }
  for(; a <= b; a++) {
    arr[a] += x;
    sum[a / k] += x;
  }  
}

void setu(int a, int b, int x) {
  upd(a / k);
  upd(b / k);
  if(b - a <= k) {
    for(; a <= b; a++) {
      sum[a / k] += x - arr[a];
      arr[a] = x;
    }
    return;
  }
  for(; a % k != 0; a++) {
    sum[a / k] += x - arr[a];
    arr[a] = x;
  }
  for(; a / k != b / k; a += k) {
    madd[a / k] = 0;
    st[a / k] = x;
    sum[a / k] = x * k; 
  }
  for(; a <= b; a++) {
    sum[a / k] += x - arr[a];
    arr[a] = x;
  }
}

long long gsum(int a, int b, long long ans = 0) {
  upd(a / k);
  upd(b / k);
  if(b - a <= k) {
    for(; a <= b; a++)
      ans += arr[a];
    return ans;
  }
  for(; a % k != 0; a++)
    ans += arr[a];
  for(; a / k != b / k; a += k)
    ans += sum[a / k];
  for(; a <= b; a++)
    ans += arr[a];
  return ans;
}

int main() {
  int n, q;
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    sum[i / k] += arr[i];
  }
  for(int i = 0; i < q; i++) {
    int a;
    cin >> a;
    if(a == 1) {
      int b, c, d;
      cin >> b >> c >> d;
      b--; c--;
      inc(b, c, d);
    }
    if(a == 2) {
      int b, c, d;
      cin >> b >> c >> d;
      b--; c--;
      setu(b, c, d);
    }
    if(a == 3) {
      int b, c;
      cin >> b >> c;
      b--; c--;
      cout << gsum(b, c) << '\n';
    }
  }
}
