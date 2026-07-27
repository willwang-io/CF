#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    int mx = -1;
    for (char &c: s) {
        mx = std::max(mx, c - 'a');
    }
    std::cout << mx + 1 << '\n';
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