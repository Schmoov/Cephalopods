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
using i64 = uint64_t;
using i32 = uint32_t;
using i16 = uint16_t;
using i8 = uint8_t;

i64 comb(int n, int k) {
    i64 res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - i + 1) / i;
    return res;
}

unsigned int nth_combination(int n, int k, i64 index) {
    unsigned int result = 0;
    int bit = 0;
    while (k) {
        i64 c = comb(n - 1 - bit, k - 1);
        if (index < c) {
            result |= 1u << (n - 1 - bit);
            --k;
        } else {
            index -= c;
        }
        ++bit;
    }
    return result;
}

i64 bijection(i64 i) {
    i64 total = 0;
    for (int k = 1; k <= 25; ++k) {
        i64 c = comb(25, k);
        if (total + c >= i) {
            i64 offset = i - total - 1;
            return nth_combination(25, k, offset);
        }
        total += c;
    }
    return -1;
}
//12 bits : all // not up,left,right,down // ul, ur, ud, lr, ld, rd // new
i16 legal(i16 neigh)
{
	i16 u = neigh >> 12;
	i16 l = neigh >> 9; l &= 7;
	i16 c = neigh >> 6; c &= 7; if (c) return 0;
	i16 r = neigh >> 3; r &= 7;
	i16 d = neigh & 7;

	i16 res = 0;
	if (u && l && r && d)
		if (u+l+r+d <= 6) res |= 1<<11;
	if (l && r && d)
		if (l+r+d <= 6) res |= 1<<10;
	if (u && r && d)
		if (u+r+d <= 6) res |= 1<<9;
	if (u && l && d)
		if (u+l+d <= 6) res |= 1<<8;
	if (u && l && r)
		if (u+l+r <= 6) res |= 1<<7;
	if (u && l)
		if (u+l <= 6) res |= 1<<6;
	if (u && r)
		if (u+r <= 6) res |= 1<<5;
	if (u && d)
		if (u+d <= 6) res |= 1<<4;
	if (l && r)
		if (l+r <= 6) res |= 1<<3;
	if (l && d)
		if (l+d <= 6) res |= 1<<2;
	if (r && d)
		if (r+d <= 6) res |= 1<<1;
	if (!res) res = 1;
	return res;
}

i16 db[077777+1];

unordered_map<i16, i16> table;
bool is_magic(i64 magic)
{
	table.clear();
	for (i64 i = 0; i <= 077777; i++) {
		i16 hash = (magic*i)>>54;
		const auto& it = table.find(hash);
		if (it == table.end())
			table[hash] = db[i];
		else if (it->second != db[i])
			return false;
    }

	return true;
}


int main ()
{
	for (i16 i = 0; i <= 077777; i++)
		db[i] = legal(i);
	table.reserve(1<<18);

	for (i64 magic = 0; bijection(magic) != -1 ; magic++) {
		if (is_magic(bijection(magic)<<39)) {
			cout << "Great Success: " << bijection(magic) << "\n";
		}
	}
}
