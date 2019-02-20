//https://codeforces.com/problemset/problem/1105/D
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int n, m, p;
int s[12], ans[12];
string S;
int f[1200][1200];
int O[20];
vector<int> X[10], Y[10];

int bfs (int V, int &head, int N){
   for (int i = 0; i < N; i++) {
	   int tail = X[V].size() - 1;
		while (head < tail) {
		   head++;
			int x = X[V][head];
			int y = Y[V][head];
			if (x + 1 < n && f[x + 1][y] == -1) {
            X[V].push_back(x + 1);
            Y[V].push_back(y);
            f[x + 1][y]=V;
         }
			if (x - 1 >= 0 && f[x - 1][y] == -1) {
            X[V].push_back(x - 1);
            Y[V].push_back(y);
            f[x-1][y]=V;
         }
			if (y + 1 < m && f[x][y + 1] == -1) {
            X[V].push_back(x);
            Y[V].push_back(y + 1);
            f[x][y + 1]=V;
         }
			if (y - 1 >= 0 && f[x][y - 1] == -1) {
            X[V].push_back(x);
            Y[V].push_back(y - 1);
            f[x][y - 1] = V;
         }
		}
		if(head + 1 == X[V].size()) return 1;
	}
	return 0;
}

int main(){
	cin >> n >> m >> p;
	for(int i = 0; i < p; i++){
      cin >> s[i];
   }
	for(int i = 0; i < n; i++){
		cin >> S;
		for (int j = 0; j < m; j++) {
         f[i][j] = -1;
			if(S[j] == '#') f[i][j] = -2;
			if('1' <= S[j] && S[j] <= '9'){
				f[i][j] = -2;
				X[S[j] - '1'].push_back(i);
				Y[S[j] - '1'].push_back(j);
			}
		}
	}
	for(int i = 0; i < p; i++) O[i] = -1;
	for(int i = 0; i < 100000000; i++){
		int o = 0;
		for (int i = 0; i < p; i++) o += bfs(i, O[i], s[i]);
		if( o == p ) break;
	}
	for(int i = 0; i < p; i++)
      cout << X[i].size() << ' ';
   return 0;
}
