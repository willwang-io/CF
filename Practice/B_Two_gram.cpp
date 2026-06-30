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

void solve() {
    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::string s;
    std::cin >> n >> s;
    std::map<std::string, int> cnt;
    int mx = 0;
    for (int i = 0; i < n - 1; ++i) {
        mx = std::max(mx, ++cnt[s.substr(i, 2)]);
    }
    for (auto &[k, v]: cnt) {
        if (v == mx) {
            std::cout << k << '\n';
            return 0;
        }
    }
}
