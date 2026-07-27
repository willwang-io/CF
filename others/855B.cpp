#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

size_t n;
std::vector<long long> a, b(3);
long long dp[100000][4];

const long long INF = 4e18;

long long dfs(size_t i, size_t j) {
    if (j == 3) {
        return 0;
    }
    if (i >= n) {
        return -INF;
    }
    if (dp[i][j] != -INF) {
        return dp[i][j];
    }
    return dp[i][j] = std::max(dfs(i + 1, j), a[i] * b[j] + dfs(i, j + 1));
}

void solve() {
    std::cin >> n >> b[0] >> b[1] >> b[2];
    a.resize(n);
    std::fill(&dp[0][0], &dp[0][0] + 100000 * 4, -INF);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::cout << dfs(0, 0) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    t = 1;

    while (t--) {
        solve();
    }
    return 0;
}