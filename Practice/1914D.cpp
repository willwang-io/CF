#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

ll n, dp[100001][8];

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n), c(n);
    for (auto &x: a) {
        std::cin >> x;
    }
    for (auto &x: b) {
        std::cin >> x;
    }
    for (auto &x: c) {
        std::cin >> x;
    }
    for (int i = 0; i <= n; ++i) {
        dp[i][7] = 0;
    }
    for (int mask = 0; mask < 7; ++mask) {
        dp[n][mask] = -4e18;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int mask = 0; mask < 7; ++mask) {
            if (mask == 7) {
                dp[i][mask] = 0;
                continue;
            }
            long long ans = dp[i + 1][mask];
            if ((mask & 1) == 0) {
                ans = std::max(ans, a[i] + dp[i + 1][mask | 1]);
            }
            if ((mask & 2) == 0) {
                ans = std::max(ans, b[i] + dp[i + 1][mask | 2]);
            }
            if ((mask & 4) == 0) {
                ans = std::max(ans, c[i] + dp[i + 1][mask | 4]);
            }
            dp[i][mask] = ans;
        }
    }
    std::cout << dp[0][0] << '\n';
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