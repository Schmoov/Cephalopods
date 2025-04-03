#pragma once
#include <bits/stdc++.h>

using namespace std;

class Grid {
public:
	int						d;
	vector<int>				g;
	vector<vector<int>>		c;

	Grid();
	Grid(Grid& og, int pos, int capt);

	void legal();
	int toInt();
	int solve();
	friend std::ostream& operator<<(std::ostream& os, Grid& grid);
};

