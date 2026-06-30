#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

void solve() {
    std::set<std::string> seen;
    int n;
    std::cin >> n;
    while (n--) {
        std::string x;
        std::cin >> x;
        std::cout << (seen.find(x) != seen.end() ? "YES\n" : "NO\n");
        seen.insert(x);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    t = 1;

    while (t--) {
        solve();
    }
    return 0;
}