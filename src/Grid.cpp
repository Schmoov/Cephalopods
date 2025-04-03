#include "../inc/Cepha.hpp"

unordered_map<ll, ll> Grid::memo;

Grid::Grid() : g(9), c(9, vector<int>(16, 0))
{
	cin >> d; cin.ignore();
	for (int i = 0; i < 9; i++) {
		cin >> g[i]; cin.ignore();
	}
	legal();
}

Grid::Grid(Grid& og, int pos, int capt) : g(9), c(9, vector<int>(16, 0))
{
	d = og.d - 1;
	g = og.g;
	capture(pos, capt, og.c[pos][capt]);
	legal();
}

void Grid::capture(int pos, int capt, int val)
{
	g[pos] = val;
	if (capt & 8)
		g[pos-3] = 0;
	if (capt & 4)
		g[pos+1] = 0;
	if (capt & 2)
		g[pos+3] = 0;
	if (capt & 1)
		g[pos-1] = 0;
}

void Grid::legal()
{
	for (int pos = 0; pos < 9; pos++) {
		if (g[pos])
			continue;
		c[pos][0] = 1;
		for (int capt = 1; capt < 16; capt++) {
			if (__builtin_popcount(capt) < 2)
				continue;
			int res = 0;
			if (capt & 8) {
				if (pos < 3 || !g[pos-3])
					continue;
				res += g[pos-3];
			}
			if (capt & 4) {
				if (pos%3 == 2 || !g[pos+1])
					continue;
				res += g[pos+1];
			}
			if (capt & 2) {
				if (pos >= 6 || !g[pos+3])
					continue;
				res += g[pos+3];
			}
			if (capt & 1) {
				if (pos%3 == 0 || !g[pos-1])
					continue;
				res += g[pos-1];
			}

			if (res > 6)
				continue;
			c[pos][0] = 0;
			c[pos][capt] = res;
		}
	}
}

ll Grid::toInt()
{
	ll res = 0;
	for (int i = 0; i < 9; i++) {
		res *= 10;
		res += g[i];
	}
	return res;
}

ll Grid::solve()
{
	ll hash = (toInt() << 8) | d;
	if (memo.find(hash) != memo.end())
		return memo[hash]; 
	//cerr << *this;
	if (!d)
		return toInt();
	ll res = 0;
	bool final = true;
	for (int pos = 0; pos < 9; pos++) {
		for (int capt = 0; capt < 16; capt++) {
			if (c[pos][capt]) {
				final = false;
				Grid next(*this, pos, capt);
				res = (res + next.solve()) % (1LL<<30);
			}
		}
	}
	if (final)
		return toInt();
	memo[hash] = res; 
	return res;
}

std::ostream& operator<<(std::ostream& os, Grid& grid)
{
	os << "depth : " << grid.d << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			os << "|" << grid.g[3*i+j];
		}
		os << "|\n";
	}
//	for (int k = 0; k < 7; k++) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			os << "|" << (grid.c[3*i+j][0] ? "V" : "X");
		}
		os << "|\n";
	}
//	}

	return os;
}
