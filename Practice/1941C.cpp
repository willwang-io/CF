#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    int ans = 0;
    std::string prev;
    for (int i = 0; i < n - 2; ++i) {
        auto tmp = s.substr(i, 3);
        if (tmp == "pie" || tmp == "map") {
            if (tmp == "pie" && prev == "map") {
                continue;
            }
            ++ans;
            ++i;
        }
        prev = tmp;
    }
    std::cout << ans << '\n';
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
