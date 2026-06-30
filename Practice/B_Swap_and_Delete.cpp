#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cassert>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define EACH(x, a) for (auto &x: a)
#define FOR(i, j, k, in) for (int i = j; i < k; i+=in)
#define RFOR(i, j, k, in) for (int i=j; i >= k; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

typedef long long int ll;

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

const int d4i[4]={-1,0,1,0}, d4j[4]={0,1,0,-1};
const int d8i[8]={-1,-1,0,1,1,1,0,-1}, d8j[8]={0,1,1,1,0,-1,-1,-1};


#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

void solve() {
    string s;
    cin >> s;
    int zero = 0, one = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') ++zero;
        else ++one;
    }
    if (one == zero) {
        cout << 0 << '\n';
        return;
    }
    int ans = 0;
    for (char &c: s) {
        if (c == '0') {
            if (one) {
                --one;
                ++ans;
            } else {
                break;
            }
        } else {
            if (zero) {
                --zero;
                ++ans;
            } else {
                break;
            }
        }
    }
    cout << s.size() - ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        solve();
    }
}