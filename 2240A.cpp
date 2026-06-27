#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void solve() {
    int n, k;
    std::cin >> n >> k;
    int ans = 0, sum = 0;
    for (int i = 0;; ++i) {
        int j = (1 << i) * k;
        if (sum + j > n) {
            ans += (n - sum) / (1 << i);
            break;
        }
        sum += j;
        ans += k;
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
    return 0;
}