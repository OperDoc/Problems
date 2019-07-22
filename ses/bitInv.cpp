#include <bits/stdc++>

using namespace std;

set<int> fs;

multiset<int> maxlen;

int[200010] lens;

int add(int x, int l) {
  lens[x] = l;
  maxlen.insert(l);
}

int take(int x) {
  return *(--fs.upper_bound(x));
}

void spl(int x, int y) {
  if(x > y) swap(x, y);
  int tx = take(x);
  if(tx == take(y)) {
    maxlen.erase(lens[tx]);
    fs.insert(y);
    lens[y] = x - y + lens[tx];
    maxlen.insert(lens[y]);
    lens[tx] = y - x;
    maxlen.insert(lens[tx]);
  }
}

void mer(int x, int y) {
  if(x > y) swap(x, y);
  int tx = take(x);
  int ty = take(y);
  while(tx != ty) {
    fs.erase(fs.find(ty));
    ty = take(y);
  }
}

void inv(int x, int y) {
  if(x > y) swap(x, y);
  if(take(x) != take(y)) {
    mer(x, y);
  } else {
    spl(x, y);
  }
}

int main() {
  string s; cin >> s;
  
  for(int i = 0; i < s.size(); i++) 
    if(i == 0 or s[i - 1] != s[i])
      fs.insert(i);
  
  int n;cin >> n;
  
  while(--n) {
    int x; cin >> x; x--;
    
    if(x != 0) inv(x - 1, x);
    if(x != n - 1) inv(x, x + 1);
  }
}
