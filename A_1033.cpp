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
#define rall(c) (c).rbegin(), (c).rend();
#define EACH(x, a) for (auto& x: a)
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

#define pb push_back
#define sz size
#define nl '\n'

typedef long long int ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VS> VVS;

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const float PI = 3.1415926535897932384626433832795;

const int d4i[4]={-1,0,1,0}, d4j[4]={0,1,0,-1};
const int d8i[8]={-1,-1,0,1,1,1,0,-1}, d8j[8]={0,1,1,1,0,-1,-1,-1};

template <class T>
void printv (const vector<T> &V) {
    EACH(v, V) cout << v << " "; 
    cout << nl;
}
template<class T> bool umin(T& a, const T& b) {return b<a?a=b, 1:0;}
template<class T> bool umax(T& a, const T& b) {return a<b?a=b, 1:0;}
void yes() {cout << "YES\n";}
void no() {cout << "NO\n";}

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

bool dfs(int i, int j, int n, VS &S) {
    if (!(i >= 0 && j >= 0 && i < n && j < n) || S[i][j] == 'x' || S[i][j] == 'A') {
        return false;
    }
    if (S[i][j] == 'C') {
        return true;
    }
    S[i][j] = 'x';
    bool ans = false;
    REP(k, 8) {
        ans |= dfs(i + d8i[k], j + d8j[k], n, S);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    VS S(n, string(n, '.'));
    int x, y;
    cin >> x >> y;
    REP(i, 8) {
        int xx = x - 1, yy = y - 1;
        while ((xx >= 0 && yy >= 0 && xx < n && yy < n)) {
            S[xx][yy] = 'A';
            xx += d8i[i];
            yy += d8j[i];
        }
    }
    int i, j;
    cin >> x >> y;
    S[x - 1][y - 1] = 'B';
    i = x - 1;
    j = y - 1;
    cin >> x >> y;
    S[x - 1][y - 1] = 'C';
    if (dfs(i, j, n, S)) {
        yes();
    } else {
        no();
    }
}
