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
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int g = a[0];
    for (int i = 1; i < n; ++i) {
        g = std::gcd(g, a[i]);
    }
    int count_g = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == g) {
            ++count_g;
        }
    }
    int cnt_not_g = n - count_g;
    if (cnt_not_g == 0) {
        std::cout << "0\n";
        return;
    }
    if (count_g > 0) {
        std::cout << cnt_not_g << '\n';
        return;
    }
    std::vector<int> vals = a;
    std::sort(vals.begin(), vals.end());
    vals.erase(std::unique(vals.begin(), vals.end()), vals.end());
    std::vector<bool> visited(vals.back() + 1, false);
    std::vector<int> dist(vals.back() + 1, 0);
    std::queue<int> q;
    for (int v: vals) {
        visited[v] = true;
        dist[v] = 0;
        q.push(v);
    }
    int dist_g = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v == g) {
            dist_g = dist[v];
            break;
        }
        for (int u: vals) {
            int d = std::gcd(v, u);
            if (!visited[d]) {
                visited[d] = true;
                dist[d] = dist[v] + 1;
                q.push(d);
            }
        }
    }
    std::cout << dist_g + cnt_not_g - 1 << '\n';
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
