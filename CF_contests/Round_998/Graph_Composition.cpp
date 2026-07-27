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
 * Created: Jan 19, 2025 @ 10:14:26
 * Author: will_wang
 */

std::vector<bool> seen, seen2;
int cnt, cnt2, n, m1, m2;
std::vector<int> col;
std::vector<std::vector<int>> adj1, adj2;
std::map<std::pair<int, int>, int> mp;

void dfs2(int u) {
    col[u] = cnt;
    seen2[u] = true;
    for (auto &v: adj2[u]) {
        if (!seen2[v]) {
            dfs2(v);
        }
    }
}

void dfs(int u) {
    seen[u] = true;
    for (auto &v: adj1[u]) {
        if (!seen[v] && mp[{u, v}] != 1) {
            dfs(v);
        }
    }
}

void solve() {
    std::cin >> n >> m1 >> m2;
    cnt = 0, cnt2 = 0;

    seen.assign(n, false);
    seen2.assign(n, false);
    adj1.assign(n, std::vector<int>());
    adj2.assign(n, std::vector<int>());
    col.assign(n, 0);
    mp.clear();

    for (int i = 0; i < m1; i++) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }

    for (int i = 0; i < m2; i++) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (!seen2[i]) {
            cnt++;
            dfs2(i);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (auto &v: adj1[i]) {
            if (col[i] != col[v]) {
                mp[std::make_pair(i, v)] = 1;
                ans++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            dfs(i);
            cnt2++;
        }
    }
    ans = ans / 2 + (cnt2 - cnt);
    std::cout << ans << '\n';
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
