/ 2018, Sayutin Dmitry.

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

int t;

pair<int, int> adv(pair<int, int> a, int val) {
    if (a.second + val > t)
        return make_pair(a.first + 1, val);
    else
        return make_pair(a.first, a.second + val);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    t = input<int>();
    int n = input<int>();

    vector<int> a(n);
    input_seq(ALL(a));

    vector<pair<int, int>> dp(n);

    dp[n - 1] = make_pair(0, a[n - 1]);

    for (int l = n - 2; l >= 0; --l) {
        vector<pair<int, int>> dp_next(n);
        dp_next[l] = make_pair(0, a[l]);
        for (int r = l + 1; r <= n - 1; ++r) {
            dp_next[r] = min(adv(dp_next[r - 1], a[r]), adv(dp[r], a[l]));
        }

        dp = std::move(dp_next);
    }

    auto res = dp[n - 1];
    cout << (res.first) + int(res.second != 0) << "\n";

    return 0;
}
