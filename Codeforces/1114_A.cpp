//https://codeforces.com/problemset/problem/1114/A/
#include<iostream>

using namespace std;

int main(){
   int x, y, z, a, b, c;
   cin >> x >> y >> z >> a >> b >> c;
   if( x <= a && x + y <= a + b && x + y + z <= a + b + c){
      cout << "YES\n";
   } else {
      cout << "NO\n";
   }
   return 0;
}
