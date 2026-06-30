#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int dp[100001][9] = {};
    int n = s.size();

    dp[n][0] = true;

    for (int i = n - 1; i >= 0; --i) {
        int cur = s[i] - '0';
        for (int j = 0; j < 9; ++j) {
            dp[i][j] = dp[i + 1][(j + cur) % 9];
            if (cur == 2 || cur == 3) {
                dp[i][j] |= dp[i + 1][(j + cur * cur) % 9];
            }
        }
    }
    std::cout << (dp[0][0] ? "YES\n" : "NO\n");
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