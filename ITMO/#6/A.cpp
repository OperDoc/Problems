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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    vector<int> a(n);

    input_seq(ALL(a));

    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i <= n - 1; ++i)
        dp[i][i] = 0;

    for (int len = 1; len <= n - 1; ++len)
        for (int i = 0; i + len <= n - 1; ++i) {
            int j = i + len;

            if (len % 2 == 0) // minimizing player
                dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]);
            else
                dp[i][j] = max(a[i] + dp[i + 1][j], dp[i][j - 1] + a[j]);
        }

    cout << dp[0][n - 1] << "\n";

    return 0;
}
