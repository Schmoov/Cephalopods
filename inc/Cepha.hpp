#pragma once
#include <bits/stdc++.h>

using namespace std;

class Grid {
public:
	int						d;
	vector<int>				g;
	vector<vector<bool>>	c;

	Grid();
	Grid(Grid& og, int pos, int capt);

	void legal();
	void capture(int pos, int capt);
	int toInt();
	int solve();
	friend std::ostream& operator<<(std::ostream& os, const Grid& grid);
};

