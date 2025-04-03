#include "../inc/Cepha.hpp"

Grid::Grid() : g(9), c(9, vector<bool>(6, false))
{
	cin >> d; cin.ignore();
	for (int i = 0; i < 9; i++) {
		cin >> g[i]; cin.ignore();
	}
	legal();
}

Grid::Grid(Grid& og, int pos, int capt) : g(9), c(9, vector<bool>(6, false))
{
	d = og.d - 1;
	g = og.g;
	capture(pos, capt);
	legal();
}

void Grid::capture(int pos, int capt)
{
	switch (capt) {
		case 0:
			g[pos] = 1;
			break;
		case 1:
			g[pos] = g[pos-3] + g[pos+1];
			break;
		case 2:
			g[pos] = g[pos-3] + g[pos+3];
			break;
		case 3:
			g[pos] = g[pos-3] + g[pos-1];
			break;
		case 4:
			g[pos] = g[pos+1] + g[pos+3];
			break;
		case 5:
			g[pos] = g[pos+1] + g[pos-1];
			break;
		case 6:
			g[pos] = g[pos+3] + g[pos-1];
			break;
		default:
			__builtin_unreachable();
	}
}

void Grid::legal()
{
	for (int pos = 0; pos < 9; pos++) {
		if (g[pos])
			continue;
		c[pos][0] = true;
		if (pos >= 3 && pos%3 < 2
			&& g[pos-3] && g[pos-3] <= 3
			&& g[pos+1] && g[pos+1] <= 3) {
			c[pos][0] = false;
			c[pos][1] = true;
		}
		if (pos >= 3 && pos < 6
			&& g[pos-3] && g[pos-3] <= 3
			&& g[pos+3] && g[pos+3] <= 3) {
			c[pos][0] = false;
			c[pos][2] = true;
		}
		if (pos >= 3 && pos%3
			&& g[pos-3] && g[pos-3] <= 3
			&& g[pos-1] && g[pos-1] <= 3) {
			c[pos][0] = false;
			c[pos][3] = true;
		}
		if (pos%3 < 2 && pos < 6
			&& g[pos+1] && g[pos+1] <= 3
			&& g[pos+3] && g[pos+3] <= 3) {
			c[pos][0] = false;
			c[pos][4] = true;
		}
		if (pos%3 < 2 && pos%3
			&& g[pos+1] && g[pos+1] <= 3
			&& g[pos-1] && g[pos-1] <= 3) {
			c[pos][0] = false;
			c[pos][5] = true;
		}
		if (pos < 6 && pos%3
			&& g[pos+3] && g[pos+3] <= 3
			&& g[pos-1] && g[pos-1] <= 3) {
			c[pos][0] = false;
			c[pos][6] = true;
		}
	}
}

int Grid::toInt()
{
	int res = 0;
	for (int i = 0; i < 9; i++) {
		res *= 10;
		res += g[i];
	}
	return res;
}

int Grid::solve()
{
	if (!d)
		return toInt();
	int res = 0;
	bool final = true;
	for (int pos = 0; pos < 9; pos++) {
		for (int capt = 0; capt <= 6; capt++) {
			if (c[pos][capt]) {
				final = false;
				Grid next(*this, pos, capt);
				res = (res + next.solve()) % (1<<30);
			}
		}
	}
	if (final)
		return toInt();
	return res;
}

std::ostream& operator<<(std::ostream& os, Grid& grid)
{
	os << "depth : " << grid.d << endl;
	for (int i = 0; i < 3; i++) {
		os << "________\n";
		for (int j = 0; j < 3; j++) {
			os << "|" << grid.g[3*i+j];
		}
		os << "|\n";
	}
	os << "________\n";

	return os;
}
