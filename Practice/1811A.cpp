#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

void solve() {
    int n, d;
    std::string s;
    std::cin >> n >> d >> s;
    bool done = false;
    for (int i = 0; i < n; ++i) {
        if (!done && s[i] - '0' < d) {
            std::cout << d;
            done = true;
        }
        std::cout << s[i];
    }
    if (!done) {
        std::cout << d;
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