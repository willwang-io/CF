#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

void solve() {
    int n;
    std::cin >> n;
    int cnt = 0;
    for (int i = 0; i < 2 * n; ++i) {
        int x;
        std::cin >> x;
        if (x & 1) ++cnt;
    }
    std::cout << (cnt == n ? "Yes\n" : "No\n");
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