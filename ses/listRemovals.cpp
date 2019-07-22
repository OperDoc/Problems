#include <iostream>

using namespace std;

const int N = 200100;
int tx[N], ty[N], tr[N], tl[N], tsz[N];
int nCount = 1;

int newNode(int x) {
  tx[nCount] = x;
  ty[nCount] = (rand() << 15) + rand();
  tsz[nCount] = 1;
  return nCount++;
}

void spl(int rt, int& l, int& r, int x) {
  if(!rt)
    return void(l = r = 0);
  if(tsz[tl[rt]] < x) {
    spl(tr[rt], tr[rt], r, x - tsz[tl[rt]] - 1);
    l = rt;
    tsz[l] = tsz[tl[l]] + tsz[tr[l]] + 1;
  } else {
    spl(tl[rt], l, tl[rt], x);
    r = rt;
    tsz[r] = tsz[tl[r]] + tsz[tr[r]] + 1;
  }
  
}

void mer(int& rt, int l, int r) {
  if(!l || !r)
    return void(rt = l ? l : r);
  if(ty[l] < ty[r]) {
    mer(tr[l], tr[l], r);
    rt = l;
  } else {
    mer(tl[r], l, tl[r]);
    rt = r;
  }
  tsz[rt] = tsz[tl[rt]] + tsz[tr[rt]] + 1;
}

void era(int& rt, int ind) {
  int l, m, r;
  spl(rt, l, r, ind + 1);
  spl(l, l, m, ind);
  mer(rt, l, r);
}

int mget(int& rt, int ind) {
  if(tsz[tl[rt]] == ind)
    return tx[rt];
  if(tsz[tl[rt]] > ind)
    return mget(tl[rt], ind);
  if (tsz[tl[rt]] < ind)
    return mget(tr[rt], ind - tsz[tl[rt]] - 1);
}

void print(int rt, int k = 0, int d = 1) {
  if(!rt)
    return;
  print(tl[rt], k, d + 1);
  cout << tsz[tl[rt]] << ':' << tx[rt] << ':' << d << ' ';
  print(tr[rt], k + tsz[tl[rt]] + 1, d + 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  srand(42);
  int n;
  cin >> n;
  int rt = newNode(0);
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    mer(rt, rt, newNode(a));
  }
  //print(rt);
  //cout << endl;
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cout << mget(rt, a) << ' ';
    era(rt, a);
  }
  cout << '\n';
}
