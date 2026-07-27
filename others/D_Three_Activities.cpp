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
typedef std::vector<ll> VI;
typedef std::pair<int, int> PII;

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define EACH(x, a) for (auto& x: a)

VI a, b, c;
ll n, dp[100001][8];


ll dfs(int i, int mask) {
    if (mask == 7) {
        return 0;
    } 
    if (i >= n) {
        return mask == 7 ? 0 : -1e18;
    }
    if (dp[i][mask] != -1) {
        return dp[i][mask];
    }
    ll ans = dfs(i + 1, mask);
    if ((mask & 1) == 0) {
        ans = std::max(ans, a[i] + dfs(i + 1, mask | 1));
    }
    if ((mask & 2) == 0) {
        ans = std::max(ans, b[i] + dfs(i + 1, mask | 2));
    }
    if ((mask & 4) == 0) {
        ans = std::max(ans, c[i] + dfs(i + 1, mask | 4));
    }
    return dp[i][mask] = ans;
}

void solve() {
    std::cin >> n;

    a.resize(n);
    b.resize(n);
    c.resize(n);

    std::memset(dp, -1, sizeof dp);

    EACH(x, a) {
        std::cin >> x;
    }
    EACH(x, b) {
        std::cin >> x;
    }
    EACH(x, c) {
        std::cin >> x;
    }
    std::cout << dfs(0, 0) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}