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
using i64 = uint64_t;
using i32 = uint32_t;
using i16 = uint16_t;
using i8 = uint8_t;
const int legal[] ={1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,2,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,4,4,4,4,1,1,8,142,142,142,142,14,8,8,8,142,142,142,14,12,8,8,8,142,142,14,12,12,8,8,8,142,14,12,12,12,8,8,8,14,12,12,12,12,8,8,1,4,4,4,4,4,1,1,1,4,4,4,4,4,1,1,1,4,4,4,4,1,1,1,8,142,142,142,14,10,8,8,8,142,142,14,14,8,8,8,8,142,14,14,12,8,8,8,8,14,14,12,12,8,8,8,1,6,4,4,4,1,1,1,1,4,4,4,4,1,1,1,1,4,4,4,4,1,1,1,1,4,4,4,1,1,1,1,8,142,142,14,10,10,8,8,8,142,14,14,10,8,8,8,8,14,14,14,8,8,8,8,1,6,6,4,1,1,1,1,1,6,4,4,1,1,1,1,1,4,4,4,1,1,1,1,1,4,4,4,1,1,1,1,1,4,4,1,1,1,1,1,8,142,14,10,10,10,8,8,8,14,14,10,10,8,8,8,1,6,6,2,1,1,1,1,1,6,6,1,1,1,1,1,1,6,4,1,1,1,1,1,1,4,4,1,1,1,1,1,1,4,4,1,1,1,1,1,1,4,1,1,1,1,1,1,8,14,10,10,10,10,8,8,1,6,2,2,2,1,1,1,1,6,2,2,1,1,1,1,1,6,2,1,1,1,1,1,1,6,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,2,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,2,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,16,16,16,16,16,1,1,32,306,306,306,306,50,32,32,32,306,306,306,50,48,32,32,32,306,306,50,48,48,32,32,32,306,50,48,48,48,32,32,32,50,48,48,48,48,32,32,1,16,16,16,16,16,1,1,1,16,16,16,16,16,1,1,64,596,596,596,596,84,64,64,1128,4094,4094,4094,2046,1150,1128,1128,1128,4094,4094,2046,1662,1148,1128,1128,1128,4094,2046,1662,1660,1148,1128,1128,1128,2046,1662,1660,1660,1148,1128,1128,104,638,636,636,636,124,104,104,64,596,596,596,596,84,64,64,64,596,596,596,596,84,64,64,64,596,596,596,84,80,64,64,1128,4094,4094,2046,1406,1146,1128,1128,1128,4094,2046,1918,1150,1144,1128,1128,1128,2046,1918,1662,1148,1144,1128,1128,104,894,638,636,124,120,104,104,96,630,628,628,116,112,96,96,64,596,596,596,84,80,64,64,64,596,596,596,84,80,64,64,64,596,596,84,80,80,64,64,1128,4094,2046,1406,1402,1146,1128,1128,1128,2046,1918,1406,1146,1144,1128,1128,104,894,894,126,120,120,104,104,96,886,630,116,112,112,96,96,96,630,628,116,112,112,96,96,64,596,596,84,80,80,64,64,64,596,596,84,80,80,64,64,64,596,84,80,80,80,64,64,1128,2046,1406,1402,1402,1146,1128,1128,104,894,382,378,122,120,104,104,96,886,374,114,112,112,96,96,96,886,118,112,112,112,96,96,96,630,116,112,112,112,96,96,64,596,84,80,80,80,64,64,64,596,84,80,80,80,64,64,64,84,80,80,80,80,64,64,104,382,378,378,378,122,104,104,96,374,370,370,114,112,96,96,96,374,370,114,112,112,96,96,96,374,114,112,112,112,96,96,96,118,112,112,112,112,96,96,64,84,80,80,80,80,64,64,64,84,80,80,80,80,64,64,1,16,16,16,16,16,1,1,32,306,306,306,306,50,32,32,32,306,306,306,50,48,32,32,32,306,306,50,48,48,32,32,32,306,50,48,48,48,32,32,32,50,48,48,48,48,32,32,1,16,16,16,16,16,1,1,1,16,16,16,16,16,1,1,1,16,16,16,16,16,1,1,32,306,306,306,306,50,32,32,32,306,306,306,50,48,32,32,32,306,306,50,48,48,32,32,32,306,50,48,48,48,32,32,32,50,48,48,48,48,32,32,1,16,16,16,16,16,1,1,1,16,16,16,16,16,1,1,1,16,16,16,16,1,1,1,32,306,306,306,50,34,32,32,32,306,306,50,50,32,32,32,32,306,50,50,48,32,32,32,32,50,50,48,48,32,32,32,1,18,16,16,16,1,1,1,1,16,16,16,16,1,1,1,1,16,16,16,16,1,1,1,64,596,596,596,84,68,64,64,1128,4094,4094,2046,1278,1134,1128,1128,1128,4094,2046,1790,1150,1132,1128,1128,1128,2046,1790,1662,1148,1132,1128,1128,104,766,638,636,124,108,104,104,72,606,604,604,92,76,72,72,64,596,596,596,84,68,64,64,64,596,596,596,84,68,64,64,64,596,596,84,84,64,64,64,1128,4094,2046,1534,1150,1130,1128,1128,1128,2046,2046,1150,1150,1128,1128,1128,104,1022,638,126,124,104,104,104,104,638,638,124,124,104,104,104,64,598,596,84,84,64,64,64,64,596,596,84,84,64,64,64,64,596,596,84,84,64,64,64,64,596,84,84,80,64,64,64,1128,2046,1534,1406,1146,1130,1128,1128,104,1022,382,126,122,104,104,104,104,894,126,126,120,104,104,104,96,630,118,116,112,96,96,96,64,598,84,84,80,64,64,64,64,596,84,84,80,64,64,64,64,596,84,84,80,64,64,64,64,84,84,80,80,64,64,64,104,510,382,378,122,106,104,104,104,382,382,122,122,104,104,104,96,374,118,114,112,96,96,96,96,118,118,112,112,96,96,96,64,86,84,80,80,64,64,64,64,84,84,80,80,64,64,64,64,84,84,80,80,64,64,64,1,20,16,16,16,1,1,1,40,318,314,314,58,42,40,40,32,310,306,50,50,32,32,32,32,310,50,50,48,32,32,32,32,54,50,48,48,32,32,32,1,22,16,16,16,1,1,1,1,20,16,16,16,1,1,1,1,20,16,16,16,1,1,1,1,16,16,16,16,1,1,1,32,306,306,306,50,34,32,32,32,306,306,50,50,32,32,32,32,306,50,50,48,32,32,32,32,50,50,48,48,32,32,32,1,18,16,16,16,1,1,1,1,16,16,16,16,1,1,1,1,16,16,16,16,1,1,1,1,16,16,16,16,1,1,1,32,306,306,306,50,34,32,32,32,306,306,50,50,32,32,32,32,306,50,50,48,32,32,32,32,50,50,48,48,32,32,32,1,18,16,16,16,1,1,1,1,16,16,16,16,1,1,1,1,16,16,16,16,1,1,1,1,16,16,16,1,1,1,1,32,306,306,50,34,34,32,32,32,306,50,50,34,32,32,32,32,50,50,50,32,32,32,32,1,18,18,16,1,1,1,1,1,18,16,16,1,1,1,1,1,16,16,16,1,1,1,1,1,16,16,16,1,1,1,1,64,596,596,84,68,68,64,64,1128,4094,2046,1278,1262,1134,1128,1128,1128,2046,1790,1278,1134,1132,1128,1128,104,766,766,126,108,108,104,104,72,734,606,92,76,76,72,72,72,606,604,92,76,76,72,72,64,596,596,84,68,68,64,64,64,596,596,84,68,68,64,64,64,596,84,84,68,64,64,64,1128,2046,1534,1278,1134,1130,1128,1128,104,1022,254,126,110,104,104,104,104,766,126,126,108,104,104,104,72,606,94,92,76,72,72,72,64,598,84,84,68,64,64,64,64,596,84,84,68,64,64,64,64,596,84,84,68,64,64,64,64,84,84,84,64,64,64,64,104,510,510,126,106,106,104,104,104,510,126,126,106,104,104,104,104,126,126,126,104,104,104,104,64,86,86,84,64,64,64,64,64,86,84,84,64,64,64,64,64,84,84,84,64,64,64,64,64,84,84,84,64,64,64,64,1,20,20,16,1,1,1,1,40,446,318,58,42,42,40,40,40,318,62,58,42,40,40,40,32,54,54,50,32,32,32,32,1,22,22,16,1,1,1,1,1,22,20,16,1,1,1,1,1,20,20,16,1,1,1,1,1,20,20,16,1,1,1,1,1,20,16,16,1,1,1,1,40,318,314,58,42,42,40,40,32,310,50,50,34,32,32,32,32,54,50,50,32,32,32,32,1,22,18,16,1,1,1,1,1,22,16,16,1,1,1,1,1,20,16,16,1,1,1,1,1,20,16,16,1,1,1,1,1,16,16,16,1,1,1,1,32,306,306,50,34,34,32,32,32,306,50,50,34,32,32,32,32,50,50,50,32,32,32,32,1,18,18,16,1,1,1,1,1,18,16,16,1,1,1,1,1,16,16,16,1,1,1,1,1,16,16,16,1,1,1,1,1,16,16,16,1,1,1,1,32,306,306,50,34,34,32,32,32,306,50,50,34,32,32,32,32,50,50,50,32,32,32,32,1,18,18,16,1,1,1,1,1,18,16,16,1,1,1,1,1,16,16,16,1,1,1,1,1,16,16,16,1,1,1,1,1,16,16,1,1,1,1,1,32,306,50,34,34,34,32,32,32,50,50,34,34,32,32,32,1,18,18,2,1,1,1,1,1,18,18,1,1,1,1,1,1,18,16,1,1,1,1,1,1,16,16,1,1,1,1,1,1,16,16,1,1,1,1,1,64,596,84,68,68,68,64,64,1128,2046,1278,1262,1262,1134,1128,1128,104,766,254,238,110,108,104,104,72,734,222,78,76,76,72,72,72,734,94,76,76,76,72,72,72,606,92,76,76,76,72,72,64,596,84,68,68,68,64,64,64,596,84,68,68,68,64,64,64,84,84,68,68,64,64,64,104,510,254,238,110,106,104,104,104,254,254,110,110,104,104,104,72,222,94,78,76,72,72,72,72,94,94,76,76,72,72,72,64,86,84,68,68,64,64,64,64,84,84,68,68,64,64,64,64,84,84,68,68,64,64,64,1,20,20,4,1,1,1,1,40,446,190,46,42,42,40,40,40,190,62,46,42,40,40,40,8,30,30,14,8,8,8,8,1,22,22,4,1,1,1,1,1,22,20,4,1,1,1,1,1,20,20,4,1,1,1,1,1,20,20,4,1,1,1,1,1,20,20,1,1,1,1,1,40,446,62,42,42,42,40,40,40,62,62,42,42,40,40,40,1,22,22,2,1,1,1,1,1,22,22,1,1,1,1,1,1,22,20,1,1,1,1,1,1,20,20,1,1,1,1,1,1,20,20,1,1,1,1,1,1,20,16,1,1,1,1,1,40,318,58,42,42,42,40,40,32,54,50,34,34,32,32,32,1,22,18,2,1,1,1,1,1,22,18,1,1,1,1,1,1,22,16,1,1,1,1,1,1,20,16,1,1,1,1,1,1,20,16,1,1,1,1,1,1,16,16,1,1,1,1,1,32,306,50,34,34,34,32,32,32,50,50,34,34,32,32,32,1,18,18,2,1,1,1,1,1,18,18,1,1,1,1,1,1,18,16,1,1,1,1,1,1,16,16,1,1,1,1,1,1,16,16,1,1,1,1,1,1,16,16,1,1,1,1,1,32,306,50,34,34,34,32,32,32,50,50,34,34,32,32,32,1,18,18,2,1,1,1,1,1,18,18,1,1,1,1,1,1,18,16,1,1,1,1,1,1,16,16,1,1,1,1,1,1,16,16,1,1,1,1,1,1,16,1,1,1,1,1,1,32,50,34,34,34,34,32,32,1,18,2,2,2,1,1,1,1,18,2,2,1,1,1,1,1,18,2,1,1,1,1,1,1,18,1,1,1,1,1,1,1,16,1,1,1,1,1,1,1,16,1,1,1,1,1,1,64,84,68,68,68,68,64,64,104,254,238,238,238,110,104,104,72,222,206,206,78,76,72,72,72,222,206,78,76,76,72,72,72,222,78,76,76,76,72,72,72,94,76,76,76,76,72,72,64,84,68,68,68,68,64,64,64,84,68,68,68,68,64,64,1,20,4,4,4,1,1,1,40,190,174,174,46,42,40,40,8,158,142,14,14,8,8,8,8,158,14,14,12,8,8,8,8,30,14,12,12,8,8,8,1,22,4,4,4,1,1,1,1,20,4,4,4,1,1,1,1,20,4,4,4,1,1,1,1,20,4,4,1,1,1,1,40,190,174,46,42,42,40,40,8,158,14,14,10,8,8,8,8,30,14,14,8,8,8,8,1,22,6,4,1,1,1,1,1,22,4,4,1,1,1,1,1,20,4,4,1,1,1,1,1,20,4,4,1,1,1,1,1,20,4,1,1,1,1,1,40,190,46,42,42,42,40,40,8,30,14,10,10,8,8,8,1,22,6,2,1,1,1,1,1,22,6,1,1,1,1,1,1,22,4,1,1,1,1,1,1,20,4,1,1,1,1,1,1,20,4,1,1,1,1,1,1,20,1,1,1,1,1,1,40,62,42,42,42,42,40,40,1,22,2,2,2,1,1,1,1,22,2,2,1,1,1,1,1,22,2,1,1,1,1,1,1,22,1,1,1,1,1,1,1,20,1,1,1,1,1,1,1,20,1,1,1,1,1,1,1,16,1,1,1,1,1,1,32,50,34,34,34,34,32,32,1,18,2,2,2,1,1,1,1,18,2,2,1,1,1,1,1,18,2,1,1,1,1,1,1,18,1,1,1,1,1,1,1,16,1,1,1,1,1,1,1,16,1,1,1,1,1,1,1,16,1,1,1,1,1,1,32,50,34,34,34,34,32,32,1,18,2,2,2,1,1,1,1,18,2,2,1,1,1,1,1,18,2,1,1,1,1,1,1,18,1,1,1,1,1,1,1,16,1,1,1,1,1,1,1,16,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,2,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,4,4,4,4,1,1,8,142,142,142,142,14,8,8,8,142,142,142,14,12,8,8,8,142,142,14,12,12,8,8,8,142,14,12,12,12,8,8,8,14,12,12,12,12,8,8,1,4,4,4,4,4,1,1,1,4,4,4,4,4,1,1,1,4,4,4,4,1,1,1,8,142,142,142,14,10,8,8,8,142,142,14,14,8,8,8,8,142,14,14,12,8,8,8,8,14,14,12,12,8,8,8,1,6,4,4,4,1,1,1,1,4,4,4,4,1,1,1,1,4,4,4,4,1,1,1,1,4,4,4,1,1,1,1,8,142,142,14,10,10,8,8,8,142,14,14,10,8,8,8,8,14,14,14,8,8,8,8,1,6,6,4,1,1,1,1,1,6,4,4,1,1,1,1,1,4,4,4,1,1,1,1,1,4,4,4,1,1,1,1,1,4,4,1,1,1,1,1,8,142,14,10,10,10,8,8,8,14,14,10,10,8,8,8,1,6,6,2,1,1,1,1,1,6,6,1,1,1,1,1,1,6,4,1,1,1,1,1,1,4,4,1,1,1,1,1,1,4,4,1,1,1,1,1,1,4,1,1,1,1,1,1,8,14,10,10,10,10,8,8,1,6,2,2,2,1,1,1,1,6,2,2,1,1,1,1,1,6,2,1,1,1,1,1,1,6,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,2,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,2,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,2,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,4,4,4,4,1,1,8,142,142,142,142,14,8,8,8,142,142,142,14,12,8,8,8,142,142,14,12,12,8,8,8,142,14,12,12,12,8,8,8,14,12,12,12,12,8,8,1,4,4,4,4,4,1,1,1,4,4,4,4,4,1,1,1,4,4,4,4,1,1,1,8,142,142,142,14,10,8,8,8,142,142,14,14,8,8,8,8,142,14,14,12,8,8,8,8,14,14,12,12,8,8,8,1,6,4,4,4,1,1,1,1,4,4,4,4,1,1,1,1,4,4,4,4,1,1,1,1,4,4,4,1,1,1,1,8,142,142,14,10,10,8,8,8,142,14,14,10,8,8,8,8,14,14,14,8,8,8,8,1,6,6,4,1,1,1,1,1,6,4,4,1,1,1,1,1,4,4,4,1,1,1,1,1,4,4,4,1,1,1,1,1,4,4,1,1,1,1,1,8,142,14,10,10,10,8,8,8,14,14,10,10,8,8,8,1,6,6,2,1,1,1,1,1,6,6,1,1,1,1,1,1,6,4,1,1,1,1,1,1,4,4,1,1,1,1,1,1,4,4,1,1,1,1,1,1,4,1,1,1,1,1,1,8,14,10,10,10,10,8,8,1,6,2,2,2,1,1,1,1,6,2,2,1,1,1,1,1,6,2,1,1,1,1,1,1,6,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,2,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,2,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

constexpr u32 M30 = 0x3fffffff;
constexpr u32 P10[9] = {100'000'000, 10'000'000, 1'000'000, 100'000, 10'000, 1'000, 100, 10, 1};

constexpr u16 neigh(u32 g, u8 pos) {
	u16 u = 7;
	if (pos < 6)
		u = (g>>(3*(pos+3))) & 7;
	u16 l = 7;
	if (pos%3 != 2)
		l = (g>>(3*(pos+1))) & 7;
	u16 r = 7;
	if (pos % 3)
		r = (g>>(3*(pos-1))) & 7;
	u16 d = 7;
	if (pos >= 3)
		d = (g>>(3*(pos-3))) & 7;
	return (u<<9)|(l<<6)|(r<<3)|d;
} 

constexpr u32 posShift(i8 val, i8 pos) {
	u32 res = val;
	return res << (3*pos);
}

u32 parse() {
	u32 g = 0;
	for (int i = 0; i < 9; i++) {
		u32 val;
		cin >> val; cin.ignore();
		g = g | (val<<(3*i));
	}
	return g;
}

using State = u32;

constexpr u8 at(State s, u8 pos) {
	return (s>>(3*pos))&7;
}

constexpr State nextS(State s, u8 pos, u8 capt) {
	u64 mask[12] = {
		0'000'000'000ULL << 12,

		0'000'007'070ULL << 12,
		0'000'700'070ULL << 12,
		0'000'707'000ULL << 12,
		0'070'000'070ULL << 12,
		0'070'007'000ULL << 12,
		0'070'700'000ULL << 12,

		0'000'707'070ULL << 12,
		0'070'007'070ULL << 12,
		0'070'700'070ULL << 12,
		0'070'707'000ULL << 12,

		0'070'707'070ULL << 12,
	};
	u32 m = mask[capt]>>(3*(8-pos));
	u32 val = s&m;
	
	val = ((val&0700700700)>>6) + ((val&0070070070)>>3) + (val&07007007);
	val = ((val&07000000)>>18) + ((val&07000)>>9) + (val&07);
	val += capt==0;
	s &= ~m;
	s |= posShift(val, pos);
	return s;
}




unordered_map<u32, u32> memo[2];


constexpr u32 output(u32 val[9]) {
	u32 res = 0;
	for (int i = 0; i < 9; i++) {
		res += val[i]*P10[i];
	}
	return res&M30;
}

u32 solve(const State og, int depth)
{
	u32 res[9] = {0};
	int new_idx = 1;
	bool sub_idx = 0;
	memo[0][og] = 1;
	for (int d = depth; d > 0; d--, sub_idx ^= 1) {
		memo[!sub_idx].clear();
		for (const auto [s, cnt] : memo[sub_idx]) {
			bool final = true;
			for (u8 pos = 0; pos < 9; pos++) {
				if (at(s,pos))
					continue;
				u16 capMask = legal[neigh(s, pos)];
				for (int capt = 0; capt < 12; capt++) {
					if (!(capMask & (1<<capt)))
						continue;
					final = false;
					State next = nextS(s, pos, capt);
					memo[!sub_idx][next] += cnt;
				}
			}
			if (final) {
				for (int i = 0; i < 9; i++)
					res[i] += at(s, i) * cnt;
			}
		}
	}
	for (const auto [s, cnt] : memo[sub_idx])
		for (int i = 0; i < 9; i++)
			res[i] += at(s, i) * cnt;
	
	return output(res);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memo[0].reserve(1<<19);
	memo[1].reserve(1<<19);

	cout << "u32 dataB[54][41]={";
	for (int i = 0; i < 54; i++) {
		State input = parse();
		cout <<"{" << input;
		for (int d = 1; d <= 40; d++) {
			cout <<"," << (solve(input, d));
			memo[0].clear();
			memo[1].clear();
		}
		cout << "},{";
	}
	cout << "};";
}
