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

#ifdef DEBUG
#define dbg(...) std::cerr << __LINE__ << ": [" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
template<class T> void dbg_out(T &&x) { std::cerr << x << "]\n"; }
template<class T, class...Args> void dbg_out(T &&x, Args&&...args) { std::cerr << x << ", "; dbg_out(args...); }
#else
#define dbg(...) 0
#endif

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define EACH(x, a) for (auto& x: a)
#define all(c) (c).begin(), (c).end()

/*
 * @author: will_wang
 * @created: 2024-12-30 19:58:47
 */
void solve() {
    int k;
    std::cin >> k;
    VI a(k);
    std::unordered_map<int, int> cnt;
    EACH(x, a) {
        std::cin >> x;
        ++cnt[x];
    }
    EACH(x, a) {
        if ((k - 2) % x == 0) {
            int y = (k - 2) / x;
            if ((y == x && cnt[y] > 1)) {
                std::cout << x << ' ' << y << '\n';
                return;
            } else if (y != x && cnt[y] > 0) {
                std::cout << x << ' ' << y << '\n';
                return;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    REP(i, t) {
        solve();
    }
}