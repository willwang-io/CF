#ifdef LOCAL
#include "../cp.hpp"
#else
#include <bits/stdc++.h>
#endif

void solve() {
    long long n;
    std::cin >> n;
    if (n == 10) {
        std::cout << "-1\n";
    }else if (n % 12 == 10) {
        std::cout << "22 " << n - 22 << '\n';
    } else {
        std::cout << n % 12 << ' ' << n - n % 12 << '\n';
    }
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