#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int grid[60][60];
int fx = -1, fy = -1, sx = -1, sy = -1;

bool in(int x, int y){
   return (fx <= x) && (x <= sx) && (fy <= y) && (y <= sy);
}

int main(){
   int n;
   cin >> n;
   for (int i = 0, a, b; i < m; i++) {
      for (int j = 0; j < n; j++) {
         cin >> grid[i][j];
      }
   }

   cout << ans << '\n';
   return 0;
}
