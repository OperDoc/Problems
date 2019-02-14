#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> p, d;
int get(int x)/*O(1)*/{
    if(x == p[x])return x;
    p[x] = get(p[x]);
    return p[x];
}
void unin(int x, int y)/*O(1)*/{
    x = get(x);
    y = get(y);
    if(x != y)
    {
        if(d[x] > d[y])swap(x,y);
        p[y] = x;
        if(d[x] == d[y])d[x]++;
    }
}
struct V{
   int a, b, c;
   V(int a, int b, int c):a(a),b(b),c(c){}
};

int f[2010];

vector<V> Vs;

bool cmp(V& a, V& b)/*O(1)*/{
    return a.c < b.c;
}
long long mino(int n)/*O(m * log(m))*/{
   long long ans = 0;
   p.resize(n, 0);
   d.resize(n, 1);
   for(int i = 0; i < n; ++i) p[i] = i;
   sort(Vs.begin(), Vs.end(), cmp);
   for(auto i:Vs){
       if(get(i.a) != get(i.b)){
         unin(i.a, i.b);
         ans += i.c;
      }
   }
   return ans;
}

int main(){
   int n;
   cin >> n;
   Vs.reserve(n * n);
   for(int i = 0; i < n; i++){
      cin >> f[i];
   }
   for(int i = 0; i < n; i++){
      for(int j = i + 1; j < n; j++){
         Vs.push_back(V(i, j, -(f[i] ^ f[j])));
      }
   }
   cout << -mino(n);
   return 0;
}
