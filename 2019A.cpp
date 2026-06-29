#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int n;
std::vector<int> a(100);
int dp[100][1001];


int dfs(int i, int max_red=0) {
    if (i >= n) {
        return max_red;
    }
    if (dp[i][max_red] != -1) {
        return dp[i][max_red];
    }
    return dp[i][max_red] = std::max(1 + dfs(i + 2, std::max(a[i], max_red)), dfs(i + 1, max_red));
}

void solve() {
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::fill(&dp[0][0], &dp[0][0] + 100 * 1001, -1);
    std::cout << dfs(0) << '\n';
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