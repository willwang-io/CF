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
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <cmath>
#include <cstring>

#ifdef DEBUG
#define dbg(...) std::cerr << __LINE__ << ": [" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
template<class T> void dbg_out(T &&x) { std::cerr << x << "]\n"; }
template<class T, class...Args> void dbg_out(T &&x, Args&&...args) { std::cerr << x << ", "; dbg_out(args...); }
#else
#define dbg(...) 0
#endif

/*
 * Created: Jan 05, 2025 @ 12:51:06
 * Author: will_wang
 */
void solve() {
    int n, l, r;
    std::cin >> n >> l >> r;
    std::vector<int> ans;
    bool ok = true;
    for (int i = 1; i < n + 1; ++i) {
        long long cur = ((l - 1) / i + 1) * i;
        ok &= cur <= r;
        ans.push_back(cur);
    }
    if (ok) {
        std::cout << "YES\n";
        for (auto &x: ans) {
            std::cout << x << ' ';
        }
        std::cout << '\n';
    } else {
        std::cout << "NO\n";
    }
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
