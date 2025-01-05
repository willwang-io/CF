#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <cmath>
#include <cstring>

typedef long long ll;
typedef std::vector<int> VI;
typedef std::pair<int, int> PII;
typedef std::vector<std::string> VS;

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define EACH(x, a) for (auto& x: a)
#define all(x) (x).begin(), (x).end()

const int INF = 1e9;
const ll LINF = 1e18;
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

#ifdef DEBUG
#define dbg(...) std::cerr << __LINE__ << ": [" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
template<class T> void dbg_out(T &&x) { std::cerr << x << "]\n"; }
template<class T, class...Args> void dbg_out(T &&x, Args&&...args) { std::cerr << x << ", "; dbg_out(args...); }
#else
#define dbg(...) 0
#endif

/*
 * @author: will_wang
 * @created: 2025-01-01 15:54:20
 */
void solve() {
    int n;
    std::cin >> n;
    VI a(n);
    ll total = 0LL;
    EACH(x, a) {
        std::cin >> x;
        total += x;
    }
    if (total == 0) {
        std::cout << 0 << '\n';
        return;
    }
    REP(i, n) {
        if (a[i] != 0) {
            while (i < n && a[i] != 0) {
                total -= a[i];
                ++i;
            }
            if (total == 0) {
                std::cout << 1 << '\n';
                return;
            } else {
                break;
            }
        }
    }
    std::cout << 2 << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
}