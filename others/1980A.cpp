#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

void solve() {
    int n, m;
    std::string s;
    std::cin >> n >> m >> s;
    std::vector<int> cnt(26, 0);
    for (auto &c: s) {
        ++cnt[c - 'A'];
    }
    int ans = 0;
    for (char c = 'A'; c <= 'G'; ++c) {
        ans += std::max(0, m - cnt[c - 'A']);
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