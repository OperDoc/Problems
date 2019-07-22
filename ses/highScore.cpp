#include <bits/stdc++.h>
 
using namespace std;
 
const long long inf = 1e18;
long long d[2510];
int e[5010][3];
 
int main() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    cin >> e[i][0] >> e[i][1] >> e[i][2];
    e[i][0]--;
    e[i][1]--;
    e[i][2] *= -1;
  }
  for(int i = 1; i < n; i++) {
    d[i] = inf;
  }
  for(int i = 0; i < n - 1; i++) 
    for(int j = 0; j < m; j++) 
      if(d[e[j][0]] != inf)
	d[e[j][1]] = min(d[e[j][1]], d[e[j][0]] + e[j][2]);
  long long ans1 = d[n - 1];
  for(int i = 0; i < n - 1; i++)
    for(int j = 0; j < m; j++) 
      if(d[e[j][0]] != inf)
	d[e[j][1]] = min(d[e[j][1]], d[e[j][0]] + e[j][2]);
  long long ans2 = d[n - 1];
  cout << (ans1 == ans2 ? -ans1 : -1) << endl;
}
