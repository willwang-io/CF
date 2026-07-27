#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x: a) std::cin >> x;
    int mn = std::abs(a[0] - a[n - 1]), x = 1, y = n;
    for (int i = 1; i < n; ++i) {
        if (std::abs(a[i] - a[i - 1]) < mn) {
            mn = std::abs(a[i] - a[i - 1]);
            x = i;
            y = i + 1; 
        }
    }
    std::cout << x << ' ' << y << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    t = 1;

    while (t--) {
        solve();
    }

    return 0;
}