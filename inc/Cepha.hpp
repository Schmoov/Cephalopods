#pragma once
#pragma GCC optimize "Ofast,unroll-loops,omit-frame-pointer,inline"
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target("rdrnd", "popcnt", "avx2", "bmi2")
#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
using board = unsigned __int128;

extern unordered_map<ll, ll> memo;

board parse();
ll solve(int d, board g);
