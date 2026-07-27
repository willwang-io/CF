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
typedef std::vector<int> VI;
typedef std::pair<int, int> PII;

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define EACH(x, a) for (auto& x: a)

/*
 * @author: will_wang
 * @created: 2024-12-29 20:28:43
 */

int n, seen[2][200001];
std::vector<std::string> a(2);

bool dfs(int i, int j, int turn=0) {
    if (i < 0 || j < 0 || i >= 2 || j >= n || seen[i][j] == 1) {
        return false;
    }
    if (i == 1 && j == n - 1) {
        return true;
    }
    seen[i][j] = 1;
    if (turn == 1) {
        if (a[i][j] == '<') {
            return dfs(i, j - 1, turn ^ 1);
        } else {
            return dfs(i, j + 1, turn ^ 1);
        }
    }
    return dfs(i + 1, j, turn ^ 1) || dfs(i - 1, j, turn ^ 1) || dfs(i, j + 1, turn ^ 1) || dfs(i, j - 1, turn ^ 1);
}

void solve() {
    std::cin >> n;
    std::cin >> a[0] >> a[1];
    std::memset(seen, 0, sizeof seen);
    std::cout << (dfs(0, 0, 0) ? "YES\n" : "NO\n");
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