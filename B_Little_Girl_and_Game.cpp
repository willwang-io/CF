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
typedef std::vector<int> vi;

#define EACH(x, a) for (auto& x: a)
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define REP(i, j) FOR(i, 0, j, 1)

void solve() {

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;

    vi cnt(26, 0);
    EACH(x, s) {
        ++cnt[x - 'a'];
    }
    int even = 0, odd = 0;
    REP(i, 26) {
        if (cnt[i] == 0) {
            continue;
        }
        if (cnt[i] % 2 == 1) {
            ++odd;
        } else {
            ++even;
        }
    }
    if (odd <= 1) {
        std::cout << "First\n";
        return 0;
    }
    std::cout << (odd % 2 == 0 ? "Second\n" : "First\n");
}