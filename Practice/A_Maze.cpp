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

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::string> g(n);
    EACH(row, g) {
        std::cin >> row;
    }
    std::queue<PII> q;
    REP(i, n) {
        REP(j, m) {
            if (g[i][j] == '#') {
                q.push(std::make_pair(i, j));
            }
        }
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
}