#pragma once
#pragma GCC optimize "Ofast,unroll-loops,omit-frame-pointer,inline"
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target("rdrnd", "popcnt", "avx2", "bmi2")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
extern unordered_map<ll, ll> memo;

class Grid {
public:
	int	d;
	int	g[9];
	int	c[9][16];
	ll sh;

	Grid();
	Grid(Grid& og, int pos, int capt);

	void legal();
	void capture(int pos, int capt, int val, ll ols_sh);
	ll toInt();
	ll solve();
	//friend std::ostream& operator<<(std::ostream& os, Grid& grid);
};

