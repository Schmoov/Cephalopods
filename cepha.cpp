#ifndef BENCH
#undef _GLIBCXX_DEBUG
#pragma GCC optimize "Ofast,unroll-loops,omit-frame-pointer,inline"
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
//ifndef __POPCNT__
#pragma GCC target("movbe,aes,pclmul,avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2,rdrnd,popcnt,bmi,bmi2,lzcnt")
//#endif
#endif
#include <bits/stdc++.h>

using namespace std;
constexpr uint M30 = 0x3fffffff;
constexpr uint P10[9] = {100'000'000, 10'000'000, 1'000'000, 100'000, 10'000, 1'000, 100, 10, 1};
const int_fast8_t perm[8][9] = {
	{0,1,2,3,4,5,6,7,8},
	{2,1,0,5,4,3,8,7,6},
	{6,7,8,3,4,5,0,1,2},
	{0,3,6,1,4,7,2,5,8},
	{8,5,2,7,4,1,6,3,0},
	{8,7,6,5,4,3,2,1,0},
	{6,3,0,7,4,1,8,5,2},
	{2,5,8,1,4,7,0,3,6}
};

struct State {
	int g[9];

	State() {
		for (int i = 0; i < 9; i++) {
			cin >> g[i]; cin.ignore();
		}
	}

	State(const State& s, int_fast8_t pos, int_fast8_t capt, int_fast8_t val) {
		memcpy(g, s.g, sizeof(g));
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

	uint32_t hash() const {
		uint32_t res = 0;
		for (int i = 0; i < 9; i++)
			res = (res << 3) | g[i];
		return res;
	}
};

void printStates(const State& s1, const State& s2) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cerr << s1.g[3*i+j] << " ";
		}
		cerr << '|';
		for (int j = 0; j < 3; j++) {
			cerr << s2.g[3*i+j] << " ";
		}
		cerr << endl;
	}
	cerr << "\n~~~~~~~~\n";
}
unordered_map<uint32_t, uint32_t> memo;

int_fast8_t legal(const State& s, int_fast8_t pos, int_fast8_t capt)
{
	int_fast8_t res = 0;
	if (capt & 8) {
		if (pos < 3 || !s.g[pos-3])
			return 0;
		res += s.g[pos-3];
	}
	if (capt & 4) {
		if (pos%3 == 2 || !s.g[pos+1])
			return 0;
		res += s.g[pos+1];
	}
	if (capt & 2) {
		if (pos >= 6 || !s.g[pos+3])
			return 0;
		res += s.g[pos+3];
	}
	if (capt & 1) {
		if (pos%3 == 0 || !s.g[pos-1])
			return 0;
		res += s.g[pos-1];
	}

	if (res > 6)
			return 0;
	return res;
}
uint outputH(uint32_t hash) {
	uint res = 0;
	uint32_t mask = 0x7;
	for (int i = 0; i < 9; i++) {
		res = (res + (hash & mask)*P10[8-i])&M30;
		hash >>= 3;
	}
	return res;
}

uint solve(const State& og, int depth)
{
	uint res = 0;
	uint32_t *arr1 = new uint32_t[1<<20];
	uint32_t *arr2 = new uint32_t[1<<20];
	uint32_t* dp[2]= {arr1, arr2};
		memset(dp[0], 0, 1<<22);
		memset(dp[1], 0, 1<<22);
	int new_idx = 1;
	bool sub_idx = 0;
	memo[og.hash()] = 0;
	dp[0][0] = 1;
	queue<State> q;
	q.push(og);
	for (int d = depth; d > 0 && !q.empty(); d--, sub_idx ^= 1) {
		//cerr << "DEPTH" << d << endl;
		int n = q.size();
		while (n--) {
			const State& s = q.front();
			int idx = memo[s.hash()];
			bool final = true;
			for (int_fast8_t pos = 0; pos < 9; pos++) {
				if (s.g[pos])
					continue;
				final = false;
				bool has_cap = false;
				for (int_fast8_t capt = 3; capt < 16; capt++) {
					if (capt == 4 || capt == 8)
						continue;
					int_fast8_t val = legal(s, pos, capt);
					if (val) {
						has_cap = true;
						State next(s, pos, capt, val);
						//printStates(s, next);
						uint32_t nextH = next.hash();
						const auto& it = memo.find(nextH);
						if (it == memo.end()) {
							memo[nextH] = new_idx;
							dp[!sub_idx][new_idx++] = dp[sub_idx][idx];
							q.push(next);
						} else {
							if(!dp[!sub_idx][it->second])
								q.push(next);
							dp[!sub_idx][it->second] += dp[sub_idx][idx];
						}
					}
				}
				if (!has_cap) {
					State next(s, pos, 0, 1);
					uint32_t nextH = next.hash();
					const auto& it = memo.find(nextH);
					if (it == memo.end()) {
						memo[nextH] = new_idx;
						dp[!sub_idx][new_idx++] = dp[sub_idx][idx];
						q.push(next);
					} else {
						if(!dp[!sub_idx][it->second])
							q.push(next);
						dp[!sub_idx][it->second] += dp[sub_idx][idx];
					}
				}
			}
			if (final) {
				res += outputH(s.hash()) * dp[sub_idx][idx];
			//	cerr <<outputH(s.hash()) << " " <<dp[sub_idx][idx] << endl;
			}
			q.pop();
		}
		memset(dp[sub_idx], 0, 1<<22);
	}
	int k = 0;
	for (const auto& it : memo) {
		res += dp[sub_idx][it.second]*outputH(it.first);
		}
	return res&M30;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memo.reserve(1<<15);

	int depth;
	cin >> depth; cin.ignore();

	State input;
	cout << (solve(input, depth)) << '\n';
}
