#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    int cnt = std::count(s.begin(), s.end(), '1'), ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ans += cnt - 1;
        } else {
            ans += cnt + 1;
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