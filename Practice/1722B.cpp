#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

void solve() {
    int n;
    std::string a, b;
    std::cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 'G' || a[i] == 'B') {
            a[i] = '*';
        }
    }
    for (int i = 0; i < n; ++i) {
        if (b[i] == 'G' || b[i] == 'B') {
            b[i] = '*';
        }
    }
    std::cout << (a == b ? "YES\n" : "NO\n");
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