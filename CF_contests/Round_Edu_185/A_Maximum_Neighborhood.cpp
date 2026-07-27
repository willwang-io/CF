#include <iostream>

void solve() {
    long long n, ans = 0;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            long long tmp = (i - 1) * n + j;
            if (i > 1) tmp += (i - 2) * n + j;
            if (i < n) tmp += i * n + j;
            if (j > 1) tmp += (i - 1) * n + (j - 1);
            if (j < n) tmp += (i - 1) * n + (j + 1);
            ans = std::max(ans, tmp);
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}