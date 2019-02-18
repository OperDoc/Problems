#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct P {
   int max_a, max_b, a = 0, b = 0;
};

int x;

int f(P& a){
   if(a.a == a.max_a) return a.b * a.b;
   if(a.b == a.max_b) return a.a * x;
   return min(a.a * x, a.b * a.b);
}

bool operator < (P& a, P& b){
   return f(a) < f(b);
}

P& pop(set<P>& ps){
   auto res = ps.begin();
   ps.erase(res);
   return res;
}

int main() {
   int n, sum = 0;
   cin >> n;
   vector<P> arr(n);
   for(int i = 0, a; i < n; i++){
      cin >> a;
      sum += a;
   }
   for(int i = 0; i < n; i++){
      cin >> arr[i].max_a;
   }
   for(int i = 0; i < n; i++){
      cin >> arr[i].max_b;
   }
   set<P> ps(arr.begin(), arr.end());
   cin >> x;
   int q = sum / 2 + 1, cnt = 0;
   while(ps.size() > 1 && cnt < q){
      auto p1 = pop(ps);
      auto p2 = pop(ps);
   }
   return 0;
}
