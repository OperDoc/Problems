#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef long long ll;
const int SIZE = 100010;
const int LOG = 20;

vector<vector<int>> Lg;
vector<int> euler;
int first[SIZE], d[SIZE], Log[2 * SIZE];
int sparse[LOG + 1][2 * SIZE];
int n = 0;

void dfs(int v, int p = -1) {
    d[v] = (p == -1 ? 0 : d[p] + 1);
    first[v] = euler.size();
    euler.push_back(v);
    for (auto i : Lg[v]) {
        if (i != p) {
            dfs(i, v);
            euler.push_back(v);
        }
    }
}

int Min(int a, int b) {
    return d[a] < d[b] ? a : b;
}

void build() {
    int l = 2 * n - 1;
    for (int i = 0; i < 2 * SIZE; i++) {
        Log[i] = (int)log2(i);
    }
    for (int i = 0; i < l; ++i) {
        sparse[0][i] = euler[i];
    }
    for (int i = 1; (1 << i) <= l; ++i) {
        for (int j = 0; j <= l - (1 << i); ++j) {
            sparse[i][j] = Min(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int getmin(int L, int R) {
    int level = Log[R - L + 1];
    return Min(sparse[level][L], sparse[level][R - (1 << level) + 1]);
}

int lca(int u, int v) {
    u = first[u];
    v = first[v];
    if (u > v) {
        swap(u, v);
    }
    return getmin(u, v);
}

int main() {
    ll ans = 0, res = 0;
    ll m, a1, a2, x, y, z;
    cin >> n >> m;
    Lg.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int _cin;
        cin >> _cin;
        Lg[_cin].push_back(i + 1);
    }
    dfs(0);
    build();
    cin >> a1 >> a2 >> x >> y >> z;
    for (int i = 0; i < m; i++) {
        ans = lca((a1 + ans) % n, a2);
        a1 = (x * a1 + y * a2 + z) % n;
        a2 = (x * a2 + y * a1 + z) % n;
        res += ans;
    }
    cout << res;
    //system("pause");
}