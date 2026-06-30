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
 * Created: Jan 05, 2025 @ 20:24:30
 * Author: will_wang
 */
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string s, t;
    std::cin >> s >> t;
    bool ok = true;
    for (int i = 1; i < (int) t.size(); ++i) {
        if (t[i] == t[i - 1]) {
            ok = false;
        }
    }
    bool ok2 = true;
    for (int i = 1; i < (int) s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            if (!ok) {
                ok2 = false;
                break;
            }
            if (s[i - 1] == t[0] || s[i] == t.back()) {
                ok2 = false;
                break;
            }
        }
    }
    std::cout << (ok2 ? "YES\n" : "NO\n");
    
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
