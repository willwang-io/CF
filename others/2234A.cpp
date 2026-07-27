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
    std::sort(a.rbegin(), a.rend());
    for (int i = 0; i < n - 2; ++i) {
        if (a[i] % a[i + 1] != a[i + 2]) {
            std::cout << "-1\n";
            return;
        }
    }
    std::cout << a[0] << ' ' << a[1] << '\n';
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