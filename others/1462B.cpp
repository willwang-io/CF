#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    if ((s.substr(0, 2) == "20" && s.substr(n - 2, 2) == "20") || s.substr(0, 4) == "2020" || s.substr(n - 4, 4) == "2020" || (s.substr(0, 1) == "2" && s.substr(n - 3, 3) == "020") || (s.substr(0, 3) == "202" && s.substr(n - 1, 1) == "0")) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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