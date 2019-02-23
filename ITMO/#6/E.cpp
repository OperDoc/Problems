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

const int max_c = 21;
const int max_n = 1.1e5;

int dp[max_c][max_n];

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    int k = min(20, input<int>());

    if (k == 0) {
        if (n == 1)
            cout << "0\n";
        else
            cout << "-1\n";

        return 0;
    }

    for (int i = 1; i < max_n; ++i)
        dp[1][i] = i - 1;

    for (int p = 2; p < max_c; ++p) {
        dp[p][1] = 0;
        int ptr = 1;
        for (int i = 2; i < max_n; ++i) {
            dp[p][i] = 1 + max(dp[p - 1][ptr], dp[p][i - ptr]);

            while (ptr + 1 < i and dp[p][i] >= 1 + max(dp[p - 1][ptr + 1], dp[p][i - ptr - 1])) {
                ++ptr;
                dp[p][i] = 1 + max(dp[p - 1][ptr], dp[p][i - ptr]);
            }
        }
    }

    cout << dp[k][n] << "\n";

    return 0;
}
