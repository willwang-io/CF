#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

void solve() {
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        int x; std::cin >> x;
        ans = std::min(ans, std::abs(0 - x));
    }
    std::cout << ans << '\n';
}