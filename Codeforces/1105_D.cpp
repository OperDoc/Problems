//https://codeforces.com/problemset/problem/1105/D
#include <iostream>
#include <queue>

using namespace std;

bool in(int a, int b, int c){
   return a <= b && b < c;
}

char g[1010][1010];
int n, m, d[1010][1010], s[1010];
int di = [1, 0, -1, 0];
int dj = [0, 1, 0, -1];

void dfs(i, j, k){
   queue<pair<int, int>> q;
   auto s = make_pair(i, j);
   d[i][j] = 0;
   int dist = 0;
   while(dist <= k ){

   }
}

int main(){
   int p;
   cin >> n >> m >> p;
   for(int i = 0; i < p; i++){
      cin >> s[i];
   }
   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         cin >> g[i][j];
      }
   }

   return 0;
}
