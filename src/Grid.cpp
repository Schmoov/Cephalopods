#include "../inc/Cepha.hpp"

board parse()
{
	board res = 0;
	for (int i = 0; i < 9; i++) {
		int value;
		cin >> value; cin.ignore();
		res |= static_cast<board>(value)<<(8*i);
	}
	return res;
}

constexpr board capture(board g, int pos, int capt, int val)
{
	board res = g | (static_cast<board>(val) << (8*pos));
	board mask = 0;
	board sub = 0xFF;
	if (capt & 8)
		mask |= sub << (8*(pos-3));
	if (capt & 4)
		mask |= sub << (8*(pos+1));
	if (capt & 2)
		mask |= sub << (8*(pos+3));
	if (capt & 1)
		mask |= sub << (8*(pos-1));
	return (res & ~mask);
}

constexpr board gAtPos(board g, int pos)
{
	board sub = 0xFF;
	return sub & (g >> (8*pos));
}

void legal(int (*c)[16], board g)
{
	for (int pos = 0; pos < 9; pos++) {
		if (gAtPos(g, pos))
			continue;
		c[pos][0] = 1;
		for (int capt = 1; capt < 16; capt++) {
			if (__builtin_popcount(capt) < 2)
				continue;
			int res = 0;
			if (capt & 8) {
				if (pos < 3 || !gAtPos(g, pos-3))
					continue;
				res += gAtPos(g, pos-3);
			}
			if (capt & 4) {
				if (pos%3 == 2 || !gAtPos(g, pos+1))
					continue;
				res += gAtPos(g, pos+1);
			}
			if (capt & 2) {
				if (pos >= 6 || !gAtPos(g, pos+3))
					continue;
				res += gAtPos(g, pos+3);
			}
			if (capt & 1) {
				if (pos%3 == 0 || !gAtPos(g, pos-1))
					continue;
				res += gAtPos(g, pos-1);
			}

			if (res > 6)
				continue;
			c[pos][0] = 0;
			c[pos][capt] = res;
		}
	}
}

ll boardHash(board g)
{
	ll res = 0;
	for (int i = 0; i < 9; i++) {
		res *= 10;
		res += gAtPos(g, i);
	}
	return res;
}

ll solve(int d, board g)
{
	if (!d)
		return boardHash(g);
	ll hash = (boardHash(g) << 8) | d;
	auto it = memo.find(hash);
	if (it != memo.end())
		return it->second; 
	
	int c[9][16] = {0};
	legal(c, g);

	ll res = 0;
	bool final = true;
	for (int pos = 0; pos < 9; pos++) {
		for (int capt = 0; capt < 16; capt++) {
			if (c[pos][capt]) {
				final = false;
				res += solve(d-1, capture(g, pos, capt, c[pos][capt]));
			}
		}
	}
	if (final)
		return boardHash(g);
	memo[hash] = res; 
	return res;
}
