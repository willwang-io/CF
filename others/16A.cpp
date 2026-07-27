#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string prev = "";
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        if (s == prev) {
            std::cout << "NO\n";
            return;
        }
        for (int j = 1; j < m; ++j) {
            if (s[j] != s[j - 1]) {
                std::cout << "NO\n";
                return;
            }
        }
        prev = s;
    }
    std::cout << "YES\n";
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