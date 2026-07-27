#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<int> seen(26, -1);
    for (int i = 0; i < n; ++i) {
        int x = s[i] - 'A';
        if (seen[x] != -1 && i - seen[x] != 1) {
            std::cout << "NO\n";
            return;
        }
        seen[x] = i;
    }
    std::cout << "YES\n";
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