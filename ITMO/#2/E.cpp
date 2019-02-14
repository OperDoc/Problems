// 0 / 100
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <complex>

using namespace std;

#define X real()
#define Y imag()
typedef complex<long double> P;

istream & operator >> (istream & in, P & a)/*O(1)*/{
    long double b, c;
    in >> b >> c;
    a = {b, c};
    return in;
}

struct L{
    long double A, B, C;
    L(long double a, long double b, long double c):A(a),B(b),C(c){}
    long double PLlen(P a)/*O(1)*/{
      return (A * a.X + B * a.Y + C)/abs(P({A, B}));
    }
};

vector<P> Ps;

bool eq(long double a, long double b)/*O(1)*/{
    long double eps = 1e-6;
    return abs(a - b) < eps;
}

int main(){
   int n, q;
   cin >> n >> q;
   Ps.resize(n);
   for(int i = 0; i < n; i++){
      cin >> Ps[i];
   }
   for(int i = 0; i < q; i++){
      int d;
      cin >> d;
      if(d == 1){
         P a;
         cin >> a;
         Ps.push_back(a);
      }else{
         long long a, b, c;
         cin >> a >> b >> c;
         L l = L(a, b, c);
         bool les = false, mor = false;
         for(int j = 0; j < Ps.size(); j++){
            if(l.PLlen(Ps[j]) < 0){
               les = true;
            }
            if(l.PLlen(Ps[j]) > 0){
               mor = true;
            }
            if(eq(l.PLlen(Ps[j]), 0)){
               cout << "NO" << '\n';
               break;
            }
         }
         if(les & mor){
            cout << "NO" << '\n';
         }else{
            cout << "YES" << '\n';
         }
      }
   }
   return 0;
}
