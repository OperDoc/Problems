//https://codeforces.com/problemset/problem/1067/B
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> G;
vector<int> dist, p;
int ans = 0;

void dfs(int v, int pv = -1){
    dist[v] = pv == -1 ? 0 : dist[pv] + 1;
    ans = dist[v] > dist[ans] ? v : ans;
    for(auto i : G[v]){
        if(i != pv){
            dfs(i, v);
            p[i] = v;
        }
    }
}

int check(int v, int pr) {
    int ans = -1;
    int cnt = 0;
    for (int u: G[v]) {
        if (u != pr) {
            cnt++;
            int cur_size = check(u, v);
            if (cur_size == -1) {
                return -1;
            }
            if (ans == -1)
                ans = cur_size;
            if (ans != cur_size) {
                return -1;
            }
        }
    }
    if (cnt == 0) return 0;
    if (cnt >= 3) return ans + 1;
    return -1;
}


int main(){
    int n, k, a, b;
    cin >> n >> k;
    G.resize(n);
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }
    bool is = true;
    dist.assign(n, -1);
    p.assign(n, -1);
    dfs(0);
    dist.assign(n, -1);
    dfs(ans);
    int curr = ans;
    while(dist[curr] != dist[ans] / 2)curr = p[curr];
    if(k == check(curr, -1)){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}
