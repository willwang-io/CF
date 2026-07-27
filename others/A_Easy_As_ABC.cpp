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


string f(const vector<string> &A, vector<vector<int>> seen, int i, int j, string cur) {
    if (i < 0 || j < 0 || i >= 3 || j >= 3 || seen[i][j]) {
        return "ZZZ";
    }
    if (cur.size() == 3) {
        return cur;
    }
    string ans = "ZZZ";
    seen[i][j] = 1;
    for (int k = 0; k < 8; ++k) {
        ans = min(ans, f(A, seen, i + d8i[k], j + d8j[k], cur + A[i][j]));
    }
    seen[i][j] = 0;
    return ans;
}

void solve() {
    vector<string> A;
    for (int i = 0; i < 3; ++i) {
        string s;
        cin >> s;
        A.push_back(s);
    }
    string ans = "ZZZ";
    vector<vector<int>> seen(3, vector<int>(3, 0));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ans = min(ans, f(A, seen, i, j, ""));
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    t = 1;

    for (int i = 0; i < t; ++i) {
        solve();
    }
}