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
 * @created: 2025-01-01 12:35:42
 */
void solve() {
    int n, d;
    std::cin >> n >> d;
    std::cout << 1 << ' ';
    if (d % 3 == 0 || n >= 3) {
        std::cout << 3 << ' ';
    }
    if (d == 5) {
        std::cout << 5 << ' ';
    }
    if (d == 7 || n >= 3) {
        std::cout << 7 << ' ';
    }
    if (n >= 6) {
        std::cout << 9 << ' ';
    } else if (n >= 3 && d % 3 == 0) {
        std::cout << 9 << ' ';
    } else if (n >= 1 && d % 9 == 0) {
        std::cout << 9 << ' ';
    }
    std::cout << '\n';
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