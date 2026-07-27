#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    if (n % 2 == 1) {
        std::cout << "NO\n";
    } else {
        if (s.substr(0, n / 2) == s.substr(n / 2)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
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