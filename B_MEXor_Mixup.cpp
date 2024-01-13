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
    int a, b;
    cin >> a >> b;
    int x;
    if (a % 4 == 1) x = a - 1;
    else if (a % 4 == 2) x = 1;
    else if (a % 4 == 3) x = a;
    else x = 0;
    
    if (x == b) {
        cout << a << nl;
    } else {
        cout << a + ((x ^ b) == a ? 2 : 1) << nl;
    }
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