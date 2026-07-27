#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

void solve() {
    ll a, b, n;
    std::cin >> a >> b >> n;
    int ans = 1;
    while (a + b <= n) {
        if (a > b) {
            std::swap(a, b);
        }
        ++ans;
        a += b;
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