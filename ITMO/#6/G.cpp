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

// suffix, who, first player score -> min ENERGY1 - ENERGY2
int64_t dp[160][2][200];

const int64_t inf = TYPEMAX(int64_t) / 5;

int get_dp(int n, int who, int64_t dlt) {
    if (dlt < -inf)
        dlt = -inf;
    else if (dlt >= +inf)
        dlt = +inf - 1;

    int ans = 0;
    while (ans < 199 and dlt >= dp[n][who][ans + 1])
        ++ans;

    if (ans == 199)
        assert(false);
    return ans;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    int A = input<int>();
    int B = input<int>();

    vector<int> nutrit(n), tasty(n);

    for (int i = 0; i != n; ++i)
        cin >> nutrit[i] >> tasty[i];

    std::reverse(ALL(nutrit));
    std::reverse(ALL(tasty));

    dp[0][0][0] = -inf;
    dp[0][1][0] = -inf;

    for (int j = 1; j < 200; ++j) {
        dp[0][0][j] = +inf;
        dp[0][1][j] = +inf;
    }

    for (int i = 1; i <= n; ++i) {
        int ntr = nutrit[i - 1];
        int tst = tasty[i - 1];

        for (int sc = 0; sc <= 199; ++sc) {
            if (1) {
                // who == 0.

                int64_t lo = -inf - 1;
                int64_t hi = +inf;

                while (hi - lo > 1) {
                    int64_t mi = lo + (hi - lo) / 2;

                    int dp_val = TYPEMIN(int);

                    dp_val = max(dp_val, tst + get_dp(i - 1, 1, mi + ntr));
                    if (mi >= 1)
                        dp_val = max(dp_val, get_dp(i - 1, 0, mi - 1 - ntr));

                    if (dp_val >= sc)
                        hi = mi;
                    else
                        lo = mi;
                }

                dp[i][0][sc] = hi;
            }

            if (1) {
                // who == 1.

                int64_t lo = -inf - 1;
                int64_t hi = +inf;

                while (hi - lo > 1) {
                    int64_t mi = lo + (hi - lo) / 2;

                    int dp_val = TYPEMAX(int);

                    dp_val = min(dp_val, get_dp(i - 1, 0, mi - ntr));
                    if (mi <= -1)
                        dp_val = min(dp_val, tst + get_dp(i - 1, 1, mi + 1 + ntr));

                    if (dp_val >= sc)
                        hi = mi;
                    else
                        lo = mi;
                }

                dp[i][1][sc] = hi;
            }
        }
    }

    int TOTAL = accumulate(ALL(tasty), 0);
    int ans = get_dp(n, 0, A - B);

    cout << ans << " " << TOTAL - ans << "\n";

    return 0;
}
