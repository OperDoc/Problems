#include <bits/stdc++.h>

using namespace std;

#define M (l + r) / 2

const int N = 2 * 1000 * 1000;
int n;

int arr[200 * 1000];
long long sum[N];
int tr[N], tl[N];
int nodeCnt = 1;

inline int newNode(int x) {
  sum[nodeCnt] = x;
  return nodeCnt++;
}

inline int  newNode() {
  return nodeCnt++;
}

int build(int l = 0, int r = n) {
  if(r - l == 1)
    return newNode(arr[l]);
  int rt = newNode();
  tl[rt] = build(l, M);
  tr[rt] = build(M, r);
  sum[rt] = sum[tl[rt]] + sum[tr[rt]];
  return rt;
}

int change(int x, int ind, int rt, int l = 0, int r = n) {
  if(r - l == 1)
    return newNode(x);
  int nrt = newNode();
  tl[nrt] = tl[rt];
  tr[nrt] = tr[rt];
  if(ind < M) {
    tl[nrt] = change(x, ind, tl[rt], l, M);
  } else {
    tr[nrt] = change(x, ind, tr[rt], M, r);
  }
  sum[nrt] = sum[tl[nrt]] + sum[tr[nrt]];
  return nrt;
}

long long gsum(int al, int ar, int rt, int l = 0, int r = n) {
  if(ar <= l or r <= al)
    return 0;
  if(al <= l and r <= ar)
    return sum[rt];
  return gsum(al, ar, tl[rt], l, M) + gsum(al, ar, tr[rt], M, r);
}

int main() {
  int q;
  cin >> n >> q;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  vector<int> trees;
  trees.push_back(build());
  for(int i = 0; i < q; i++) {
    int a;
    cin >> a;
    if(a == 1) {
      int b, c, d;
      cin >> b >> c >> d;
      trees[b - 1] = change(d, c - 1, trees[b - 1]); 
    }
    if(a == 2) {
      int b, c, d;
      cin >> b >> c >> d;
      cout << gsum(c - 1, d, trees[b - 1]) << '\n';
    }
    if(a == 3) {
      int b;
      cin >> b;
      trees.push_back(trees[b - 1]);
    }
  }
}
