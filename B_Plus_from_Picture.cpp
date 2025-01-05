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

#ifdef DEBUG
#define dbg(...) std::cerr << __LINE__ << ": [" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
template<class T> void dbg_out(T &&x) { std::cerr << x << "]\n"; }
template<class T, class...Args> void dbg_out(T &&x, Args&&...args) { std::cerr << x << ", "; dbg_out(args...); }
#else
#define dbg(...) 0
#endif

/*
 * @author: will_wang
 * @created: 2024-12-29 20:49:43
 */
void solve() {
    int h, w;
    std::cin >> h >> w;
    VS a(h);
    int cnt = 0;
    EACH(row, a) {
        std::cin >> row;
        EACH(c, row) {
            if (c == '*') {
                ++cnt;
            }
        }
    }
    bool ok = false;
    REP(i, h) {
        REP(j, w) {
            if (a[i][j] == '.') {
                continue;
            }
            if (i+1<h && a[i+1][j]=='*' && j+1<w && a[i][j+1]=='*' && i-1>=0 && a[i-1][j]=='*' && j-1>=0 && a[i][j-1]=='*' && !ok) {
                int ii = i + 1;
                while (ii < h && a[ii][j] == '*') {
                    a[ii][j] = '.';
                    ++ii;
                    --cnt;
                }
                ii = i - 1;
                while (ii >= 0 && a[ii][j] == '*') {
                    a[ii][j] = '.';
                    --ii;
                    --cnt;
                }
                int jj = j + 1;
                while (jj < w && a[i][jj] == '*') {
                    a[i][jj] = '.';
                    ++jj;
                    --cnt;
                }
                jj = j - 1;
                while (jj >= 0 && a[i][jj] == '*') {
                    a[i][jj] = '.';
                    --jj;
                    --cnt;
                }
                a[i][j] = '.';
                --cnt;
                ok = true;
            } 
        }
    }
    std::cout << (ok && cnt == 0 ? "YES\n" : "NO\n");
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