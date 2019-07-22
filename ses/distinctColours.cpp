#include<bits/stdc++.h>

using namespace std;

const int k = 500;
int arr[200010];
int arr2[200010];
int fst[200010];
int sz[200010];
int cnt = 1;
pair<pair<int, int> int> qs[200010];
bool is[200010];

int dfs(int i, int p) {
  arr2[cnt] = arr[i];
  fst[i] = cnt++;
  sz[i] = 1;
  for(auto j : g[i]) {
    if(j != p)
      sz[i] += dfs(j, i);
  }
  return sz[i];
}

bool cmp(pair<pair<int, int>, int>& i, pair<pair<int, int>, int>& j) {
  if(i.forst.first / k != j.first.first / k)
    return i.first.first < j.first.first;
  return i.first.second < j.first.second; 
}

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  map<int, int> mp;
  int cont = 1;
  for(int i = 0; i < n; i++) {
    if(mp[arr[i]] == 0)
      mp[arr[i]] = cont++;
    arr[i] = mp[arr[i]];
  }
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }
  dfs(0);
  for(int i = 0; i < n; i++) 
    qs[i] = make_pair(make_pair(fst[i] + 1, fst[i] + sz[i]), i);
  sort(qs, qs + n, cmp);
  int l = 1, r = 0;
  for(int i = 0; i < n; i++) {
    
  }
}
