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
    int n, m;
    std::cin >> n >> m;
    std::string a, b;
    std::cin >> a >> b;
    int i = 0;
    for (int j = 0; j < m; ++j) {
        if (i < n && a[i] == b[j]) {
            ++i;
        }
    }
    std::cout << i << '\n';
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
