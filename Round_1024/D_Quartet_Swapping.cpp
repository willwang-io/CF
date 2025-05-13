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


struct BIT {
    std::vector<int> f;
    BIT(int n) : f(n + 1) {}
    void update(int i) {
        for (++i; i < (int) f.size(); i += i & -i) {
            f[i]++;
        }
    }
    int query(int i) {
        int s = 0;
        for (++i; i > 0; i -= i & -i) {
            s += f[i];
        }
        return s;
    }
};

int parity(const std::vector<int>& v) {
    int m = (int) v.size();
    std::vector<std::pair<int,int>> p;
    for (int i = 0; i < m; ++i) {
        p.emplace_back(v[i], i);
    }
    std::sort(p.begin(), p.end());
    std::vector<int> pos(m);
    for (int i = 0; i < m; ++i) {
        pos[p[i].second] = i;
    }
    BIT bit(m);
    int par = 0;
    for (int i = 0; i < m; ++i) {
        int x = pos[i];
        int cnt = bit.query(m - 1) - (x ? bit.query(x - 1) : 0);
        par ^= (cnt & 1);
        bit.update(x);
    }
    return par;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> seg[2];
    for (int i = 0; i < n; ++i) {
        seg[i & 1].push_back(a[i]);
    }
    std::sort(seg[0].begin(), seg[0].end());
    std::sort(seg[1].begin(), seg[1].end());
    auto helper = [&](int d) -> std::vector<int> {
        if (d >= 0) {
            auto& s = seg[d];
            std::swap(s[s.size() - 2], s.back());
        }
        std::vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = seg[i & 1][i / 2];
        }
        if (d >= 0) {
            auto& s = seg[d];
            std::swap(s[s.size() - 2], s.back());
        }
        return ans;
    };
    int p0 = parity(seg[0]), p1 = parity(seg[1]);
    auto ans = (p0 == p1 ? helper(-1) : std::min(helper(0), helper(1)));
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << ' ';
    }
    std::cout << '\n';
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
