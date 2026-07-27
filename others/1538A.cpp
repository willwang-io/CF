#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int ans = 0, tmp = n + 1;
    for (int i = 0; i < n && tmp; ++i) {
        ++ans;
        if (a[i] == 1) {
            --tmp;
        } else if (a[i] == n) {
            tmp -= n;
        }
    }
    int ans2 = 0;
    tmp = n + 1;
    for (int i = n - 1; i >= 0 && tmp; --i) {
        ++ans2;
        if (a[i] == 1) {
            --tmp;
        } else if (a[i] == n) {
            tmp -= n;
        }
    }
    int ans3 = 0;
    for (int i = 0; i < n; ++i) {
        ++ans3;
        if (a[i] == 1 || a[i] == n) {
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        ++ans3;
        if (a[i] == 1 || a[i] == n) {
            break;
        }
    }
    std::cout << std::min(ans, std::min(ans2, ans3)) << '\n';
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