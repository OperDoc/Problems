#include <bits/stdc++.h>

using namespace std;

typedef long long C;
typedef complex<C> P;
#define X real()
#define Y imag()

P points[2010];
int pr[2010];


bool eq(double a, double b) {
  doublr e = 0.000001d;
  return abs(a - b) < e;
}

long long cp(P a, P b) {
  return a.X * b.Y - b.X * a.Y;
}

long long dp(P a, P b) {
  return a.X * b.X + a.Y * b.Y
}

int main() {
  int a, b, c, d, n;
  cin >> a >> b >> n;
  for(int i = 0; i < n; i++) {
    cin >> c >> d;
    points[i] = {c - a, d - b};
  }
  for(int i = 0; i < n; i++) pr[i] = -1;
  for(int i = 0; i < n; i++) {
    if(pr[i] != -1) continue;
    for(int j = i + 1; j < n; j++) {
      if(pr[i] != -1) continue;
      if(points[i].X * points[j].Y == points[j].X * points[i].Y and
	 (points[i].X * points[j].X <= 0 or points[i].Y * points[j].Y <= 0)) {
	pr[i] = j;
	pr[j] = i;
	break;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    if(pr[i] == -1) continue;
    for(int j = i + 1; j < n; j++) {
      if(pr[j] == i or pr[j] == -1) continue;
      if(() and ()) {
	cout << "YES" << endl;
	cout << i << ' ' << pr[i] << ' ' << j << ' ' << pr[j] << endl;
	return 0;
      }
    }
  }
  cout << "NO" << endl;
}
