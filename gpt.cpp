#include <unordered_map>
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
using u64 = uint64_t;
using u32 = uint32_t;
using u16 = uint16_t;
using u8 = uint8_t;
const u64 U = 0'070'000'000ULL << (3*4);
const u64 L = 0'000'700'000ULL << (3*4);
const u64 C = 0'000'070'000ULL << (3*4);
const u64 R = 0'000'007'000ULL << (3*4);
const u64 D = 0'000'000'070ULL << (3*4);
constexpr u32 M30 = 0x3fffffff;
constexpr u64 capMask[12] = {0, R|D, L|D, L|R, U|D, U|R, U|L, L|R|D, U|R|D, U|L|D, U|L|R, U|L|R|D};
constexpr u32 P10[9] = {100'000'000, 10'000'000, 1'000'000, 100'000, 10'000, 1'000, 100, 10, 1};

constexpr u16 neigh(u32 g, u8 pos) {
	constexpr u16 oobMask[9] = {077, 07, 0707, 070, 0, 0700, 07070, 07000, 07700};
	u64 hood = g;
	hood <<= 3*(8-pos); 
	hood = ((hood&U)>>(3*8)) | ((hood&L)>>(3*7)) | ((hood&R)>>(3*6)) | ((hood&D)>>(3*5));
	return hood | oobMask[pos];
} 
constexpr u32 posShift(u8 val, u8 pos) {
	u32 res = val;
	return res << (3*pos);
}

constexpr u8 at(u32 s, u8 pos) {
	return (s>>(3*pos))&7;
}

constexpr u32 nextS(u32 s, u8 pos, u8 capt) {
	u32 m = capMask[capt]>>(3*(8-pos));

	u32 val = s&m;
	val = val*0111111111;
	val = (val>>(3*8))&7;
	val += capt==0;
	return (s&~m) | posShift(val, pos);
}

constexpr u32 output(u32 val[9]) {
	u32 res = 0;
	for (int i = 0; i < 9; i++) {
		res += val[i]*P10[i];
	}
	return res&M30;
}

//Bucket : depth and count
using Bucket = deque<pair<u32, u32>>;
//From board hash to count per depth
unordered_map<u32, Bucket> memo[10];

void addToRes(u32 *res, u32 board, u32 cnt) {
	for (int pos = 0; pos < 9; pos++) {
		res[pos] += cnt * at(board, pos);
	}
}

void addToRes(u32 *res, u32 board, Bucket buck) {
	for (auto [_, cnt] : buck) {
		for (int pos = 0; pos < 9; pos++) {
			res[pos] += cnt * at(board, pos);
		}
	}
	buck.clear();
}
	
void parse() {
	int depth;
	cin >> depth; cin.ignore();

	u32 g = 0;
	int die = 0;

	for (int i = 0; i < 9; i++) {
		u32 val;
		cin >> val; cin.ignore();
		if (val) die++;
		g = g | (val<<(3*i));
	}
	memo[die][g].push_front({depth, 1});
}

void bucketTransfer(u32 *res, u32 board, Bucket buck, int idx)
{
	for (auto [depth, count] : buck) {
		if (depth == 1)
			addToRes(res, board, count);
		else
			memo[idx][board].push_front({depth-1, count});
	}
	buck.clear();
}

constexpr int dieChange[12] = {1,-1,-1,-1,-1,-1,-1,-2,-2,-2,-2,-3};

void solve()
{
	u32 res[9] = {0};
	bool running = true;

	while (running) {
		running = false;
		for (auto& [board, buck] : memo[9])
			addToRes(res, board, buck);
		for (int die = 8; die >= 0; die--) {
			for (auto& [board, buck] : memo[die]) {
				for (int pos = 0; pos < 9; pos++) {
					if (at(board, pos))
						continue;
					running = true;
					u16 capFlag = legal[neigh(board, pos)];
					for (int capt = 0; capt < 12; capt++) {
						if (!(capFlag & (1<<capt)))
							continue;
						u32 next = nextS(board, pos, capt);
						bucketTransfer(res, next, buck, die + dieChange[capt]); 
					}
				}
			}
		}
	}
	cout << output(res) << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}
