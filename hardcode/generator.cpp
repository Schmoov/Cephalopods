#ifndef BENCH
#undef _GLIBCXX_DEBUG
#pragma GCC optimize "Ofast,unroll-loops,omit-frame-pointer,inline"
//#pragma GCC optimize "Ofast,unroll-loops,omit-frame-pointer"
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target("movbe,aes,pclmul,avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2,rdrnd,popcnt,bmi,bmi2,lzcnt")
#endif
#include <x86intrin.h> 
#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;
using u32 = uint32_t;
using u16 = uint16_t;
using u8 = uint8_t;

constexpr u32 M30 = 0x3fffffff;
constexpr u32 P10[9] = {100'000'000, 10'000'000, 1'000'000, 100'000, 10'000, 1'000, 100, 10, 1};

using State = u32;
const u32 HASHMAX = (1<<18);
constexpr State p1(State s) {
	return 
		((s&(0'700'007'000))>>6)
		| ((s&(0'070'000'000))>>12)
		| ((s&(0'007'000'000))>>18)
		| ((s&(0'000'700'007))<<6)
		| (s&(0'000'070'000))
		| ((s&(0'000'000'700))<<18)
		| ((s&(0'000'000'070))<<12);
}
constexpr State p2(State s) {
	return 
		((s&(0'700'000'000))>>24)
		| ((s&(0'070'000'000))>>18)
		| ((s&(0'007'000'000))>>12)
		| ((s&(0'000'700'000))>>6)
		| (s&(0'000'070'000))
		| ((s&(0'000'007'000))<<6)
		| ((s&(0'000'000'700))<<12)
		| ((s&(0'000'000'070))<<18)
		| ((s&(0'000'000'007))<<24);
}
constexpr State p3(State s) {
	return 
		((s&(0'700'000'000))>>18)
		| ((s&(0'070'000'700))>>6)
		| ((s&(0'007'000'070))<<6)
		| ((s&(0'000'700'000))>>12)
		| (s&(0'000'070'000))
		| ((s&(0'000'007'000))<<12)
		| ((s&(0'000'000'007))<<18);
}
constexpr State p4(State s) {
	return 
		(s&(0'070'070'070))
		| ((s&(0'700'700'700))>>6)
		| ((s&(0'007'007'007))<<6);
}
constexpr State p5(State s) {
	return 
		(s&0'700'070'007)
		| ((s&(0'070'007'000))>>6)
		| ((s&(0'007'000'000))>>12)
		| ((s&(0'000'700'070))<<6)
		| ((s&(0'000'000'700))<<12);
}
constexpr State p6(State s) {
	return 
		((s&(0'777'000'000))>>18)
		| (s&(0'000'777'000))
		| ((s&(0'000'000'777))<<18);
}
constexpr State p7(State s) {
	return 
		((s&(0'700'000'000))>>24)
		| ((s&(0'070'700'000))>>12)
		| (s&(0'007'070'700))
		| ((s&(0'000'007'070))<<12)
		| ((s&(0'000'000'007))<<24);
}

pair<u32, u8> canon(State s) {
	u32 pr = 0;
	u32 st[8] = {s, p1(s), p2(s), p3(s), p4(s), p5(s), p6(s), p7(s)};
	for (int i = 1; i < 8; i++)
		if (st[i] < st[0])
			st[0] = st[i], pr = i;
	return {st[0], pr};
}
constexpr u32 posShift(u8 val, u8 pos) {
	u32 res = val;
	return res << (3*pos);
}
constexpr int at(State s, u8 pos) {
	return (s>>(3*pos))&7;
}

int main()
{
	for (int i = 0; i < 9; i++) {
		for (int vi = 1; vi < 7; vi++) {
			State curr = 0;
			curr |= posShift(vi, i);
			//for (int depth = 1; depth <= 40; depth++) {
			//	cout << depth << "\n";
				for (int i = 0; i < 9; i++) {
					cout << at(curr, i) << ( " ");
				}
				cout << "\n";
			//}
		}
	}
}




