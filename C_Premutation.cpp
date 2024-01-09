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
    int n;
    cin >> n;
    int arr[n][n-1];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            cin >> arr[i][j];
        }
    }
    int ans[n + 1], prev = -1;
    for (int j = 0; j < n - 1; ++j) {
        int x = -1, y = -1, cnt_x = 0, cnt_y = 0;
        for (int i = 0; i < n; ++i) {
            int cur = arr[i][j];
            if (x == -1 || x == cur) {
                x = cur;
                ++cnt_x;
            } else if (y == -1 || y == cur) {
                y = cur;
                ++cnt_y;
            }
        }
        if (j == 0) {
            if (cnt_x > cnt_y) {
                ans[j] = x;
                prev = y;
            } else {
                ans[j] = y;
                prev = x;
            }
        } else {
            ans[j] = prev;
            if (x != prev) prev = x;
            else prev = y;
        }
    }
    ans[n - 1] = prev;
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << nl;

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