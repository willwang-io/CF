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

ll a[2][100001], n, dp[2][100001];

ll dfs(int i, int j) {
    if (i >= n) {
        return 0;
    }
    if (dp[j][i] != -1) {
        return dp[j][i];
    }
    return dp[j][i] = std::max(a[j][i] + dfs(i + 1, j ^ 1), std::max(dfs(i + 1, j), dfs(i + 1, j ^ 1)));
}



void solve() {
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[0][i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> a[1][i];
    }
    std::memset(dp, -1, sizeof dp);
    std::cout << std::max(dfs(0, 0), dfs(0, 1)) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    t = 1;
    while (t--) {
        solve();
    }
}