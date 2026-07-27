#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using ll = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::set<char> seen;
    int ans = 0;
    for (auto &x: s) {
        seen.insert(x);
        ans += (int) seen.size();
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