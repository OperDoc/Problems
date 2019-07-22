#include <bits/stdc++.h>

using namespace std;

const int k = 500;
long long arr[k * k];
long long sum[k], madd[k], cnt[k];

void upd(int a) {
  if(madd[a] == 0)
    return; 
  for(int i = 0; i < k; i++)
    arr[a * k + i] += madd[a] + i * cnt[a];
  madd[a] = 0;
  cnt[a] = 0;
}
		       
void inc(int a, int b) {
  upd(a / k);
  upd(b / k);
  if(b - a <= k) {
    for(int i = 0; (a + i) <= b; i++) {
      sum[(a + i) / k] += i + 1;
      arr[a + i] += i + 1;
    }
    return;
  }
  int i = 0;
  for(; (a + i) % k != 0; i++) {
    sum[(a + i) / k] += i + 1;
    arr[a + i] += i + 1;
  }
  for(; (a + i) / k != b / k; i += k) {
    madd[(a + i) / k] += i + 1;
    sum[(a + i) / k] += (i + 1 + i + k) * k / 2;
    cnt[(a + i) / k]++;
  }
  for(; (a + i) <= b; i++) {
    arr[a + i] += i + 1;
    sum[(a + i) / k] += i + 1;
  }
}

long long gsum(int a, int b, long long ans = 0) {
  upd(a / k);
  upd(b / k);
   if(b - a <= k) {
    for(int i = 0; (a + i) <= b; i++)
      ans += arr[a + i];
    return ans;
  }
  int i = 0;
  for(; (a + i) % k != 0; i++)
    ans += arr[a + i];
  for(; (a + i) / k != b / k; i += k)
    ans += sum[(a + i) / k];
  for(; (a + i) <= b; i++)
    ans += arr[a + i];
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
    int a, b, c;
    cin >> a >> b >> c;
    if(a == 1) {
      inc(b - 1, c - 1);
    } else {
      cout << gsum(b - 1, c - 1) << '\n'; 
    }
  }
}


 



