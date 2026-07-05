#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <iostream>
#include <utility>
#include <vector>

template <class T>
void _print(const T& x) {
    std::cerr << x;
}

template <class A, class B>
void _print(const std::pair<A, B>& p) {
    std::cerr << '(';
    _print(p.first);
    std::cerr << ", ";
    _print(p.second);
    std::cerr << ')';
}

template <class T>
void _print(const std::vector<T>& v) {
    std::cerr << '[';
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (i) std::cerr << ", ";
        _print(v[i]);
    }
    std::cerr << ']';
}

inline void dbg_out() {
    std::cerr << '\n';
}

template <class T, class... Args>
void dbg_out(const T& x, const Args&... args) {
    _print(x);
    if constexpr (sizeof...(args)) {
        std::cerr << ", ";
        dbg_out(args...);
    } else {
        std::cerr << '\n';
    }
}

#define dbg(...) std::cerr << __LINE__ << ": [" << #__VA_ARGS__ << "] = ", dbg_out(__VA_ARGS__)

#endif