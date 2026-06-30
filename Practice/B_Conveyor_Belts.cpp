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
#define EACH(x, a) for (auto& x: a)
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

#define nl '\n'
#define vt vector
typedef long long int ll;

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

const int d4i[4]={-1,0,1,0}, d4j[4]={0,1,0,-1};
const int d8i[8]={-1,-1,0,1,1,1,0,-1}, d8j[8]={0,1,1,1,0,-1,-1,-1};

template <class T> void printv (const vector<T> &V) {for(auto& v:  V) cout << v << " ";cout << nl;}

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

vt<vt<int>> adj;
vt<int> seen;

void solve() {
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    int a = min(min(x1, n - x1 + 1), min(y1, n - y1 + 1));
    int b = min(min(x2, n - x2 + 1), min(y2, n - y2 + 1));
    cout << abs(a - b) << nl;
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