// 2018, Sayutin Dmitry.

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::tuple;
using std::make_tuple;
using std::get;

using std::min;
using std::abs;
using std::max;

using std::unique;
using std::sort;
using std::generate;
using std::reverse;
using std::min_element;
using std::max_element;

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

template <typename T>
T input() {
    T res;
    cin >> res;
    LASSERT(cin);
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

#define pb push_back
#define eb emplace_back

const int max_n = 2.01e6;
const int L = -1e6;
const int R = int(+1e6) + 1;

struct line {
    int k;
    int64_t b;

    int64_t eval(int x) {
        return k * int64_t(x) + b;
    }
};

bool has[4 * max_n];
line lines[4 * max_n];

void add_line(int v, int l, int r, line ln) {
    if (not has[v]) {
        lines[v] = ln;
        has[v] = 1;

        return;
    }

    int m = l + (r - l) / 2;
    if (lines[v].eval(m) < ln.eval(m))
        std::swap(ln, lines[v]);

    // lines[v].eval(m) >= ln.eval(m)

    if (l == r - 1)
        return;

    if (ln.k >= lines[v].k)
        add_line(2 * v + 2, m, r, ln);
    else
        add_line(2 * v + 1, l, m, ln);
}

int64_t get(int v, int l, int r, int x) {
    int64_t res = TYPEMIN(int64_t);

    if (has[v])
        res = max(res, lines[v].eval(x));

    if (l != r - 1) {
        int m = l + (r - l) / 2;

        if (x < m)
            res = max(res, get(2 * v + 1, l, m, x));
        else
            res = max(res, get(2 * v + 2, m, r, x));
    }

    return res;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();

    vector<int> x(n), c(n), t(n);
    for (int i = 0; i != n; ++i)
        cin >> x[i] >> c[i] >> t[i];

    add_line(0, L, R, line {x[n - 1], 0 + t[n - 1]});

    int64_t dp_val = 0;
    for (int i = n - 2; i >= 0; --i) {
        dp_val = max(int64_t(c[i]) * x[i] + get(0, L, R, -c[i]),
                     -int64_t(c[i]) * x[i] + get(0, L, R, c[i]));

        add_line(0, L, R, line {x[i], dp_val + t[i]});
    }

    cout << dp_val << "\n";

    return 0;
}
