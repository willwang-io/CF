#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> ans;
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < 4; ++j) {
            if (s[j] == '#') {
                ans.push_back(j + 1);
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        std::cout << ans[i] << ' ';
    }
    std::cout << '\n';
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