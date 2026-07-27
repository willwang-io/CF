#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int cnt = 0;
    for (auto &x: a) {
        std::cin >> x;
        if (x == 2) {
            ++cnt;
        }
    }
    if (cnt & 1) {
        std::cout << "-1\n";
        return;
    }
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 2) {
            ++tmp;
        }
        if (tmp == cnt / 2) {
            std::cout << i + 1 << '\n';
            break;
        }
    }
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