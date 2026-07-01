#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x: a) {
        std::cin >> x;
    }
    for (int i = 0; i < n - 2; ++i) {
        if (a[i] < 0) {
            std::cout << "NO\n";
            return;
        }
        int x = a[i];
        a[i] -= x;
        a[i + 1] -= 2 * x;
        a[i + 2] -= x;
    }
    for (auto &x: a) {
        if (x != 0) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
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