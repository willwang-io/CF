#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif

using ll = long long;

std::vector<int> a, b;
std::vector<std::vector<int>> dp;
int n, m;

int dfs(int i, int j) {
    if (i > n || j > m) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    if (a[i] == b[j]) {
        return dp[i][j] = 1 + dfs(i + 1, j + 1);
    }
    return dp[i][j] = std::max(dfs(i + 1, j), dfs(i, j + 1));
}

void solve() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    n = s1.size();
    m = s2.size();

    a.assign(n + 1, 0);
    b.assign(m + 1, 0);
    dp.assign(n + 1, std::vector<int>(m + 1, -1));

    for (int i = 0; i < n; ++i) {
        a[i + 1] = (a[i] + s1[i] - '0') % 10;
    }

    for (int i = 0; i < m; ++i) {
        b[i + 1] = (b[i] + s2[i] - '0') % 10;
    }

    if (a[n] != b[m]) {
        std::cout << "-1\n";
        return;
    }

    std::cout << dfs(1, 1) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}