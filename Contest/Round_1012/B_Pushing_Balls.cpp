#include <map>
#include <set>
#include <array>
#include <cmath>
#include <queue>
#include <bitset>
#include <chrono>
#include <random>
#include <ranges>
#include <vector>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <functional>

#ifdef DEBUG
#define dbg(...) std::cerr << __LINE__ << ": [" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
template<class T> void dbg_out(T &&x) { std::cerr << x << "]\n"; }
template<class T, class...Args> void dbg_out(T &&x, Args&&...args) { std::cerr << x << ", "; dbg_out(args...); }
#else
#define dbg(...) 0
#endif

/*
 * Created: Mar 22, 2025 @ 23:36:28
 * Author: will_wang
 */
void solve(){
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> g(n);
    for (int i = 0; i < n; ++i) { std::cin >> g[i]; }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '1') {
                bool ok = false;
                for (int k = 0; k < j; ++k) {
                    if (g[i][k] == '0') {
                        ok = true;
                        break;
                    }
                }
                bool ok2 = false;
                for (int k = 0; k < i; ++k) {
                    if (g[k][j] == '0') {
                        ok2 = true;
                        break;
                    }
                }
                if (ok && ok2) {
                    std::cout << "NO\n";
                    return;
                }
            }
        }
    }
    std::cout << "YES\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        // std::cout << "Case #" << (i + 1) << ": ";
        solve();
    }
}
