#include <iostream>
#include <string>
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
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define EACH(x, a) for (auto& x: a)
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

#define pb push_back
#define sz size

typedef long long int ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI; 
typedef vector<VS> VVS;

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const float PI = 3.1415926535897932384626433832795;

const int d4i[4]={-1,0,1,0}, d4j[4]={0,1,0,-1};
const int d8i[8]={-1,-1,0,1,1,1,0,-1}, d8j[8]={0,1,1,1,0,-1,-1,-1};

template<class T> void print_v(vector<T> &V) {EACH(v, V) cout << v << " "; cout << endl;}
template<class T> bool umin(T& a, const T& b) {return b<a?a=b, 1:0;}
template<class T> bool umax(T& a, const T& b) {return a<b?a=b, 1:0;}
void yes() {cout << "YES\n";}
void no() {cout << "NO\n";}

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

void solve() {

}

int main() {
    int n;
    cin >> n;
    VS A;
    REP(i, n + 1) {
        string cur;
        FOR(j, 0, n - i, 1) {
            cur += "  ";
        }
        FOR(j, 0, i, 1) {
            cur += to_string(j) + " ";
        }
        string tmp = cur;
        reverse(all(tmp));
        cur += to_string(i) + tmp;
        while (!cur.empty() && cur.back() == ' ') {
            cur.pop_back();
        }
        A.pb(cur);
    }
    EACH(a, A) {
        cout << a << '\n';
    }
    RFOR(i, n - 1, 0, 1) {
        cout << A[i] << '\n';
    }
}