#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define p_l 2 * v + 1 
#define p_r 2 * v + 2 

typedef long long ll;

const int SIZE = 300228;
const ll inf = 1e12;

int n;
int vdata[SIZE];
vector<int> gr[SIZE];

int l;
int first[SIZE];
int d[SIZE];
vector<int> euler;
int lcat[8 * SIZE];

int down[SIZE];
int up[SIZE];
int len[SIZE];
int w[SIZE];
vector<int> vert[SIZE];
vector<int> c[SIZE];
vector<bool> is_change[SIZE];

void push(int v, int i) {
    if (is_change[i][v]) {
        is_change[i][v] = false;
        is_change[i][p_l] = true;
        is_change[i][p_r] = true;
        c[i][p_l] = c[i][v];
        c[i][p_r] = c[i][v];
    }

}

int dfs(int v, int p) {
    d[v] = (p == -1 ? 0 : d[p] + 1);
    first[v] = euler.size();
    euler.push_back(v);
    w[v] = 1;
    for (auto i : gr[v]) {
        if (i != p) {
            w[v] += dfs(i, v);
            euler.push_back(v);
        }
    }
    down[v] = v;
    up[v] = p;
    len[v] = 1;
    vert[v].push_back(v);
    for (auto i : gr[v]) {
        if (i != p && w[i] * 2 >= w[v]) {
            down[v] = down[i];
            up[down[v]] = p;
            len[down[v]]++;
            vert[down[v]].push_back(v);
            break;
        }
    }
    return w[v];
}

inline int Min(int u, int v) {
    return d[u] < d[v] ? u : v;
}

void buildlca(int v, int l, int r) {
    if (l == r - 1) {
        lcat[v] = euler[l];
        return;
    }
    int m = (l + r) / 2;
    buildlca(p_l, l, m);
    buildlca(p_r, m, r);
    lcat[v] = Min(lcat[p_l], lcat[p_r]);
}

int minlca(int v, int l, int r, int askl, int askr) {
    if (askl >= r || l >= askr) {
        return n;
    }
    if (l >= askl && r <= askr) {
        return lcat[v];
    }
    int m = (l + r) / 2;
    return Min(minlca(p_l, l, m, askl, askr),
               minlca(p_r, m, r, askl, askr));
}

inline int lca(int u, int v) {
    u = first[u];
    v = first[v];
    if (u > v) {
        swap(u, v);
    }
    return minlca(0, 0, l, u, v + 1);
}

void changehld(int v, int l, int r, int askl, int askr, int i, int data) {
    if (askr <= l || r <= askl) {
        return;
    }
    if (askl <= l && r <=askr) {
        is_change[i][v] = true;
        c[i][v] = data;
        return;
    }
    push(v, i);
    int m = (r + l) / 2;
    changehld(p_l, l, m, askl, askr, i, data);
    changehld(p_r, m, r, askl, askr, i, data);
}

int go(int v, int l, int r, int pos, int i) {
    if (l == r - 1) {
        return c[i][v];
    }
    int m = (l + r) / 2;
    push(v, i);
    if (pos < m) {
        go(p_l, l, m, pos, i);
    } else {
        go(p_r, m, r, pos, i);
    }
}

inline void lineway(int u, int v, int data) {
    while (down[u] != down[v]) {
        //query here
        changehld(0, 0, len[down[u]], d[down[u]] - d[u], len[down[u]], down[u], data);
        u = up[down[u]];
    }
    //query here
    changehld(0, 0, len[down[u]], d[down[u]] - d[u], d[down[v]] - d[v] + 1, down[u], data);
}
inline int is_on(int v) {
    return go(0, 0, len[down[v]], d[down[v]] - d[v], down[v]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        gr[u - 1].push_back(v - 1);
        gr[v - 1].push_back(u - 1);
    }
    euler.reserve(2 * n - 1);
    dfs(0, -1);
    d[n] = n + 1;
    l = 2 * n - 1;
    buildlca(0, 0, l);
    for (int i = 0; i < n; ++i) {
        if (down[i] == i) {
            c[i].resize(4 * len[i], 0);
            is_change[i].resize(4 * len[i], false);
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 2) {
            int v, u, v_is_on, u_is_on;
            cin >> v >> u;
            v--;
            u--;
            v_is_on = is_on(v);
            u_is_on = is_on(u);
            cout << (u_is_on == v_is_on && u_is_on != 0) << '\n';
        } else {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            int uvlca = lca(u, v);
            lineway(u, uvlca, i + 1);
            lineway(v, uvlca, i + 1);
        }
    }
    return 0;
}