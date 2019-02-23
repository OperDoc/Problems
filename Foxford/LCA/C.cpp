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

inline int Min(int a, int b) {
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

inline int getmin(int L, int R) {
    int level = Log[R - L + 1];
    return Min(sparse[level][L], sparse[level][R - (1 << level) + 1]);
}

inline int lca(int u, int v) {
    u = first[u];
    v = first[v];
    if (u > v) {
        swap(u, v);
    }
    return getmin(u, v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while (n != 0)
    {
        Lg.resize(n);
        for (int i = 0; i < n - 1; i++) {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            tmp1--;
            tmp2--;
            Lg[tmp1].push_back(tmp2);
            Lg[tmp2].push_back(tmp1);
        }
        dfs(0);
        build();
        int m;
        cin >> m;
        int root = 0;
        for (int i = 0; i < m; i++) {
            char a;
            cin >> a;
            if (a == '?') {
                int h1, h2;
                cin >> h1 >> h2;
                h1--;
                h2--;
                cout << (lca(h1, root) ^ lca(h1, h2) ^ lca(h2, root)) + 1 << '\n';
            } else {
                cin >> root;
                root--;
            }
        }
        cin >> n;
        Lg.clear();
        euler.clear();
        //system("pause");
    }
}