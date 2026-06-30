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
 * Created: Jan 05, 2025 @ 14:45:27
 * Author: will_wang
 */
void solve() {
    int n, k1, k2, w, b;
    std::cin >> n >> k1 >> k2 >> w >> b;
    int vw = std::min(k1, k2);
    int hw = (std::max(k1, k2) - vw) / 2;
    int l1 = n - k1, l2 = n - k2;
    int vb = std::min(l1, l2);
    int hb = (std::max(l1, l2) - vb) / 2;
    if (vw + hw >= w && vb + hb >= b) {
        std::cout << "YES\n";
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
