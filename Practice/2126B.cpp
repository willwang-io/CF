#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void solve() {
    int n, k;
    std::cin >> n >> k;
    int ans = 0, cur_k = 0, is_break = false;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x == 1 || is_break) {
            is_break = false;
            cur_k = 0;
        } else {
            if (++cur_k == k) {
                ++ans;
                is_break = true;
                cur_k = 0;
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