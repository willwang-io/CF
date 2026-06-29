#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int dp[101];

int dfs(int n) {
    if (n == 0) {
        return 0;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    int ans = 1 + dfs(n - 1);
    if (n >= 3) {
        ans = std::min(ans, dfs(n - 3));
    }
    if (n >= 5) {
        ans = std::min(ans, dfs(n - 5));
    }
    return dp[n] = ans;
}

void solve() {
    int n;
    std::cin >> n;
    std::fill(&dp[0], &dp[0] + 101, -1);
    std::cout << dfs(n) << '\n';
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