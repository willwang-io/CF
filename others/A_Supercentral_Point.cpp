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
    
}

struct Point {
    int x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vt<Point> pts(n);
    for (auto &pt: pts) {
        cin >> pt.x >> pt.y;
    }
    int ans = 0;
    for (auto &p1: pts) {
        int up = 0, down = 0, right = 0, left = 0;
        for (auto &p2: pts) {
            if (p1.y == p2.y && p1.x > p2.x) {
                right = 1;
            }
            if (p1.y == p2.y && p1.x < p2.x) {
                left = 1;
            }
            if (p1.x == p2.x && p1.y < p2.y) {
                down = 1;
            }
            if (p1.x == p2.x && p1.y > p2.y) {
                up = 1;
            }
        }
        if (up + down + right + left == 4) {
            ++ans;
        }
    }
    cout << ans << nl;
}