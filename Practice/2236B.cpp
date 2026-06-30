#ifdef LOCAL
#include "../cp.hpp"
#else
#include <bits/stdc++.h>
#endif

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::string s;
        std::cin >> n >> k >> s;
        for (int i = 0; i < n - k; ++i) {
            if (s[i] == '1') {
                s[i] = '0';
                s[i + k] = s[i + k] == '0' ? '1' : '0';
            }
        }
        bool ok = true;
        for (auto &c: s) {
            if (c == '1') {
                ok = false;
            }
        }
        std::cout << (ok ? "YES\n" : "NO\n");
        
    }

    return 0;
}