#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void solve() {
    std::string s;
    std::cin >> s;
    std::vector<std::string> a = {"00", "25", "50", "75"};
    int ans = 1e9;
    for (auto &t: a) {
        int j = 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == t[j]) {
                --j;
                if (j < 0) {
                    ans = std::min(ans, (int) s.size() - i - 2);
                }
            }
        }
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