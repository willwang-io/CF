#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int cnt = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (s[i - 1] == '1' && s[i + 1] == '1') {
            s[i] = '1';
        }
    }
    int mx = std::count(s.begin(), s.end(), '1');
    for (int i = 1; i < n - 1; ++i) {
        if (s[i - 1] == '1' && s[i + 1] == '1') {
            s[i] = '0';
        }
    }
    int mn = std::count(s.begin(), s.end(), '1');
    std::cout << mn << ' ' << mx << '\n';
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