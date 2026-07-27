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
 * Created: Mar 22, 2025 @ 08:36:25
 * Author: will_wang
 */
void solve() {

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) { std::cin >> a[i]; }
    std::vector<std::pair<int, int>> ans;

    auto f = [](const std::vector<int>& b) -> int {
        int sz = (int) b.size();
        std::vector<bool> ok(sz + 1, false);
        for (int x: b) {
            if (x < (int) ok.size()) {
                ok[x] = true;
            }
        }
        for (int i = 0; i < (int) ok.size(); ++i) {
            if (!ok[i]) {
                return i;
            }
        }
        return sz + 1;
    };

    while (a.size() > 1) {
        if (std::find(a.begin(), a.end(), 0) == a.end()) {
            ans.push_back({1, (int) a.size()});
            a = {f(a)};
        } else {
            int i = 0;
            while (a[i] != 0) {
                ++i;
            }
            if (i == (int) a.size() - 1) {
                i = a.size() - 2;
            }
            std::vector<int> seg = {a[i], a[i + 1]};
            a[i] = f(seg);
            a.erase(a.begin() + i + 1);
            ans.push_back({i + 1, i + 2});
        }
    }
    std::cout << ans.size() << '\n';
    for (auto &x: ans) {
        std::cout << x.first << ' ' << x.second << '\n';
    }
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
