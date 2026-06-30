#include <iostream>
#include <string>
#include <vector>
#include <algorithm>



void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> g(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> g[i];
    }
    std::string s = "vika";
    int k = 0;
    for (int j = 0; j < m; ++j) {
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            if (g[i][j] == s[k]) {
                ok = true;
            }
        }
        if (ok) {
            ++k;
        }
        if (k == 4) {
            std::cout << "YES\n";
            return;
        }
    }
    std::cout << "NO\n";
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