#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

int n;
std::vector<ll> a;
ll dp[200000][2];
const ll INF = 4e18;

ll dfs(int i, int flipped) {
    if (i + 1 >= n) {
        return flipped ? -a[n - 1] : a[n - 1];
    }
    if (dp[i][flipped] != -INF) {
        return dp[i][flipped];
    }
    ll cur = flipped ? -a[i] : a[i];
    return dp[i][flipped] = std::max(cur + dfs(i + 1, 0), -cur + dfs(i + 1, 1));
}

void solve() {
    std::cin >> n;
    a.resize(n);
    for (auto &x: a) {
        std::cin >> x;
    }
    std::fill(&dp[0][0], &dp[0][0] + 200000 * 2, -INF);
    std::cout << dfs(0, 0) << '\n';
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