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
constexpr int M30 = 0x3fffffff;
constexpr int P10[9] = {100'000'000, 10'000'000, 1'000'000, 100'000, 10'000, 1'000, 100, 10, 1};
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

struct alignas(64) State {
	const int_fast8_t d;
	int g[9];

	State(const int_fast8_t depth) : d(depth) {
		for (int i = 0; i < 9; i++) {
			cin >> g[i]; cin.ignore();
		}
	}
	State(const State& s, int_fast8_t pos, int_fast8_t capt, int_fast8_t val) : d(s.d-1) {
		for (int i = 0; i < 9; i++)
			g[i] = s.g[i];
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

	constexpr pair<size_t, int_fast8_t> hash() const;
};

struct Value {
	int v[9];

	const Value& operator=(const State& s) {
		memcpy(v, s.g, sizeof(v));
		return *this;
	}

	void operator+=(const Value& o) {
		for (int i = 0; i < 9; i++) v[i] += o.v[i];
	}

	int output() const {
		int res = 0;
		for (int i = 0; i < 9; i++) {
			res = res + v[i]*P10[i];
		}
		return res&M30;
	}
};
unordered_map<size_t, Value> memo;

constexpr pair<size_t, int_fast8_t> State::hash() const {
	pair<size_t, int_fast8_t> res = {SIZE_MAX, 0};
	for (int k = 0; k < 8; k++) {
		size_t alt = d;
		for (int i = 0; i < 9; i++)
			alt = (alt << 4) | g[perm[k][i]];
		if (alt < res.first) {
			res.first = alt;
			res.second = k;
		}
	}
	return res;
}

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

constexpr void permute(Value& v, const Value& og, const int_fast8_t k)
{
	for (int i = 0; i < 9; i++)
		v.v[i] = og.v[perm[k][i]];
}

void solve(const State& s, Value& v)
{
	if (!s.d) {
		v = s;
		return;
	}

	pair<size_t, int_fast8_t> hash = s.hash();
	const auto& it = memo.find(hash.first);
	if (it != memo.end()) {
		int_fast8_t k = hash.second;
		if (k==7)
			k=6;
		else if (k==6)
			k=7;
		permute(v, it->second, k);
		return;
	} 
	Value res{0};
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
				Value child{0};
				solve(next, child);
				res+=child;
			}
		}
		if (!has_cap) {
			State next(s, pos, 0, 1);
			Value child{0};
			solve(next, child);
			res+=child;
		} 
	}
	if (final)
		res = s;

	permute(memo[hash.first], res, hash.second);
	v=res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memo.reserve(1<<19);

	int depth;
	cin >> depth; cin.ignore();

	State input(depth);
	Value ans{0};
	solve(input, ans);

	cout << (ans.output()) << "\n";
}
