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
typedef std::vector<std::string> VS;

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define EACH(x, a) for (auto& x: a)

/*
 * @author: will_wang
 * @created: 2024-12-29 20:49:43
 */
void solve() {
    int h, w;
    std::cin >> h >> w;
    VS a(h);
    EACH(row, a) {
        std::cin >> row;
    }
    int cnt = 0;
    REP(i, h) {
        REP(j, w) {
            if (a[i][j] == '*') {
                
            }
        }
    }
    std::cout << (cnt == 1 ? "YES\n" : "NO\n");
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