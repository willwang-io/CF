#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <cmath>
#include <cstring>

typedef long long ll;

void solve() {
    int n;
    std::cin >> n;
    std::string a, b, c;
    std::cin >> a >> b >> c;
    bool ok = false;
    for (int i = 0; i < n; ++i) {
        if (a[i] != c[i] && b[i] != c[i]) {
            ok = true;
        }
    }
    std::cout << (ok ? "YES\n" : "NO\n");

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        solve();
    }
}
