#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void solve() {
    std::vector<std::string> g(3);
    for (int i = 0; i < 3; ++i) {
        std::cin >> g[i];
    }
    if (g[0][0] == g[2][2] && g[0][1] == g[2][1] && g[0][2] == g[2][0] && g[1][0] == g[1][2]) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;

    while (t--) {
        solve();
    }
    return 0;
}