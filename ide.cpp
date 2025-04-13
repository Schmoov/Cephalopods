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
const u32 legal[] ={1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,2,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,4,4,4,4,1,1,8,142,142,142,142,14,8,8,8,142,142,142,14,12,8,8,8,142,142,14,12,12,8,8,8,142,14,12,12,12,8,8,8,14,12,12,12,12,8,8,1,4,4,4,4,4,1,1,1,4,4,4,4,4,1,1,1,4,4,4,4,1,1,1,8,142,142,142,14,10,8,8,8,142,142,14,14,8,8,8,8,142,14,14,12,8,8,8,8,14,14,12,12,8,8,8,1,6,4,4,4,1,1,1,1,4,4,4,4,1,1,1,1,4,4,4,4,1,1,1,1,4,4,4,1,1,1,1,8,142,142,14,10,10,8,8,8,142,14,14,10,8,8,8,8,14,14,14,8,8,8,8,1,6,6,4,1,1,1,1,1,6,4,4,1,1,1,1,1,4,4,4,1,1,1,1,1,4,4,4,1,1,1,1,1,4,4,1,1,1,1,1,8,142,14,10,10,10,8,8,8,14,14,10,10,8,8,8,1,6,6,2,1,1,1,1,1,6,6,1,1,1,1,1,1,6,4,1,1,1,1,1,1,4,4,1,1,1,1,1,1,4,4,1,1,1,1,1,1,4,1,1,1,1,1,1,8,14,10,10,10,10,8,8,1,6,2,2,2,1,1,1,1,6,2,2,1,1,1,1,1,6,2,1,1,1,1,1,1,6,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,2,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,2,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,16,16,16,16,16,1,1,32,306,306,306,306,50,32,32,32,306,306,306,50,48,32,32,32,306,306,50,48,48,32,32,32,306,50,48,48,48,32,32,32,50,48,48,48,48,32,32,1,16,16,16,16,16,1,1,1,16,16,16,16,16,1,1,64,596,596,596,596,84,64,64,1128,4094,4094,4094,2046,1150,1128,1128,1128,4094,4094,2046,1662,1148,1128,1128,1128,4094,2046,1662,1660,1148,1128,1128,1128,2046,1662,1660,1660,1148,1128,1128,104,638,636,636,636,124,104,104,64,596,596,596,596,84,64,64,64,596,596,596,596,84,64,64,64,596,596,596,84,80,64,64,1128,4094,4094,2046,1406,1146,1128,1128,1128,4094,2046,1918,1150,1144,1128,1128,1128,2046,1918,1662,1148,1144,1128,1128,104,894,638,636,124,120,104,104,96,630,628,628,116,112,96,96,64,596,596,596,84,80,64,64,64,596,596,596,84,80,64,64,64,596,596,84,80,80,64,64,1128,4094,2046,1406,1402,1146,1128,1128,1128,2046,1918,1406,1146,1144,1128,1128,104,894,894,126,120,120,104,104,96,886,630,116,112,112,96,96,96,630,628,116,112,112,96,96,64,596,596,84,80,80,64,64,64,596,596,84,80,80,64,64,64,596,84,80,80,80,64,64,1128,2046,1406,1402,1402,1146,1128,1128,104,894,382,378,122,120,104,104,96,886,374,114,112,112,96,96,96,886,118,112,112,112,96,96,96,630,116,112,112,112,96,96,64,596,84,80,80,80,64,64,64,596,84,80,80,80,64,64,64,84,80,80,80,80,64,64,104,382,378,378,378,122,104,104,96,374,370,370,114,112,96,96,96,374,370,114,112,112,96,96,96,374,114,112,112,112,96,96,96,118,112,112,112,112,96,96,64,84,80,80,80,80,64,64,64,84,80,80,80,80,64,64,1,16,16,16,16,16,1,1,32,306,306,306,306,50,32,32,32,306,306,306,50,48,32,32,32,306,306,50,48,48,32,32,32,306,50,48,48,48,32,32,32,50,48,48,48,48,32,32,1,16,16,16,16,16,1,1,1,16,16,16,16,16,1,1,1,16,16,16,16,16,1,1,32,306,306,306,306,50,32,32,32,306,306,306,50,48,32,32,32,306,306,50,48,48,32,32,32,306,50,48,48,48,32,32,32,50,48,48,48,48,32,32,1,16,16,16,16,16,1,1,1,16,16,16,16,16,1,1,1,16,16,16,16,1,1,1,32,306,306,306,50,34,32,32,32,306,306,50,50,32,32,32,32,306,50,50,48,32,32,32,32,50,50,48,48,32,32,32,1,18,16,16,16,1,1,1,1,16,16,16,16,1,1,1,1,16,16,16,16,1,1,1,64,596,596,596,84,68,64,64,1128,4094,4094,2046,1278,1134,1128,1128,1128,4094,2046,1790,1150,1132,1128,1128,1128,2046,1790,1662,1148,1132,1128,1128,104,766,638,636,124,108,104,104,72,606,604,604,92,76,72,72,64,596,596,596,84,68,64,64,64,596,596,596,84,68,64,64,64,596,596,84,84,64,64,64,1128,4094,2046,1534,1150,1130,1128,1128,1128,2046,2046,1150,1150,1128,1128,1128,104,1022,638,126,124,104,104,104,104,638,638,124,124,104,104,104,64,598,596,84,84,64,64,64,64,596,596,84,84,64,64,64,64,596,596,84,84,64,64,64,64,596,84,84,80,64,64,64,1128,2046,1534,1406,1146,1130,1128,1128,104,1022,382,126,122,104,104,104,104,894,126,126,120,104,104,104,96,630,118,116,112,96,96,96,64,598,84,84,80,64,64,64,64,596,84,84,80,64,64,64,64,596,84,84,80,64,64,64,64,84,84,80,80,64,64,64,104,510,382,378,122,106,104,104,104,382,382,122,122,104,104,104,96,374,118,114,112,96,96,96,96,118,118,112,112,96,96,96,64,86,84,80,80,64,64,64,64,84,84,80,80,64,64,64,64,84,84,80,80,64,64,64,1,20,16,16,16,1,1,1,40,318,314,314,58,42,40,40,32,310,306,50,50,32,32,32,32,310,50,50,48,32,32,32,32,54,50,48,48,32,32,32,1,22,16,16,16,1,1,1,1,20,16,16,16,1,1,1,1,20,16,16,16,1,1,1,1,16,16,16,16,1,1,1,32,306,306,306,50,34,32,32,32,306,306,50,50,32,32,32,32,306,50,50,48,32,32,32,32,50,50,48,48,32,32,32,1,18,16,16,16,1,1,1,1,16,16,16,16,1,1,1,1,16,16,16,16,1,1,1,1,16,16,16,16,1,1,1,32,306,306,306,50,34,32,32,32,306,306,50,50,32,32,32,32,306,50,50,48,32,32,32,32,50,50,48,48,32,32,32,1,18,16,16,16,1,1,1,1,16,16,16,16,1,1,1,1,16,16,16,16,1,1,1,1,16,16,16,1,1,1,1,32,306,306,50,34,34,32,32,32,306,50,50,34,32,32,32,32,50,50,50,32,32,32,32,1,18,18,16,1,1,1,1,1,18,16,16,1,1,1,1,1,16,16,16,1,1,1,1,1,16,16,16,1,1,1,1,64,596,596,84,68,68,64,64,1128,4094,2046,1278,1262,1134,1128,1128,1128,2046,1790,1278,1134,1132,1128,1128,104,766,766,126,108,108,104,104,72,734,606,92,76,76,72,72,72,606,604,92,76,76,72,72,64,596,596,84,68,68,64,64,64,596,596,84,68,68,64,64,64,596,84,84,68,64,64,64,1128,2046,1534,1278,1134,1130,1128,1128,104,1022,254,126,110,104,104,104,104,766,126,126,108,104,104,104,72,606,94,92,76,72,72,72,64,598,84,84,68,64,64,64,64,596,84,84,68,64,64,64,64,596,84,84,68,64,64,64,64,84,84,84,64,64,64,64,104,510,510,126,106,106,104,104,104,510,126,126,106,104,104,104,104,126,126,126,104,104,104,104,64,86,86,84,64,64,64,64,64,86,84,84,64,64,64,64,64,84,84,84,64,64,64,64,64,84,84,84,64,64,64,64,1,20,20,16,1,1,1,1,40,446,318,58,42,42,40,40,40,318,62,58,42,40,40,40,32,54,54,50,32,32,32,32,1,22,22,16,1,1,1,1,1,22,20,16,1,1,1,1,1,20,20,16,1,1,1,1,1,20,20,16,1,1,1,1,1,20,16,16,1,1,1,1,40,318,314,58,42,42,40,40,32,310,50,50,34,32,32,32,32,54,50,50,32,32,32,32,1,22,18,16,1,1,1,1,1,22,16,16,1,1,1,1,1,20,16,16,1,1,1,1,1,20,16,16,1,1,1,1,1,16,16,16,1,1,1,1,32,306,306,50,34,34,32,32,32,306,50,50,34,32,32,32,32,50,50,50,32,32,32,32,1,18,18,16,1,1,1,1,1,18,16,16,1,1,1,1,1,16,16,16,1,1,1,1,1,16,16,16,1,1,1,1,1,16,16,16,1,1,1,1,32,306,306,50,34,34,32,32,32,306,50,50,34,32,32,32,32,50,50,50,32,32,32,32,1,18,18,16,1,1,1,1,1,18,16,16,1,1,1,1,1,16,16,16,1,1,1,1,1,16,16,16,1,1,1,1,1,16,16,1,1,1,1,1,32,306,50,34,34,34,32,32,32,50,50,34,34,32,32,32,1,18,18,2,1,1,1,1,1,18,18,1,1,1,1,1,1,18,16,1,1,1,1,1,1,16,16,1,1,1,1,1,1,16,16,1,1,1,1,1,64,596,84,68,68,68,64,64,1128,2046,1278,1262,1262,1134,1128,1128,104,766,254,238,110,108,104,104,72,734,222,78,76,76,72,72,72,734,94,76,76,76,72,72,72,606,92,76,76,76,72,72,64,596,84,68,68,68,64,64,64,596,84,68,68,68,64,64,64,84,84,68,68,64,64,64,104,510,254,238,110,106,104,104,104,254,254,110,110,104,104,104,72,222,94,78,76,72,72,72,72,94,94,76,76,72,72,72,64,86,84,68,68,64,64,64,64,84,84,68,68,64,64,64,64,84,84,68,68,64,64,64,1,20,20,4,1,1,1,1,40,446,190,46,42,42,40,40,40,190,62,46,42,40,40,40,8,30,30,14,8,8,8,8,1,22,22,4,1,1,1,1,1,22,20,4,1,1,1,1,1,20,20,4,1,1,1,1,1,20,20,4,1,1,1,1,1,20,20,1,1,1,1,1,40,446,62,42,42,42,40,40,40,62,62,42,42,40,40,40,1,22,22,2,1,1,1,1,1,22,22,1,1,1,1,1,1,22,20,1,1,1,1,1,1,20,20,1,1,1,1,1,1,20,20,1,1,1,1,1,1,20,16,1,1,1,1,1,40,318,58,42,42,42,40,40,32,54,50,34,34,32,32,32,1,22,18,2,1,1,1,1,1,22,18,1,1,1,1,1,1,22,16,1,1,1,1,1,1,20,16,1,1,1,1,1,1,20,16,1,1,1,1,1,1,16,16,1,1,1,1,1,32,306,50,34,34,34,32,32,32,50,50,34,34,32,32,32,1,18,18,2,1,1,1,1,1,18,18,1,1,1,1,1,1,18,16,1,1,1,1,1,1,16,16,1,1,1,1,1,1,16,16,1,1,1,1,1,1,16,16,1,1,1,1,1,32,306,50,34,34,34,32,32,32,50,50,34,34,32,32,32,1,18,18,2,1,1,1,1,1,18,18,1,1,1,1,1,1,18,16,1,1,1,1,1,1,16,16,1,1,1,1,1,1,16,16,1,1,1,1,1,1,16,1,1,1,1,1,1,32,50,34,34,34,34,32,32,1,18,2,2,2,1,1,1,1,18,2,2,1,1,1,1,1,18,2,1,1,1,1,1,1,18,1,1,1,1,1,1,1,16,1,1,1,1,1,1,1,16,1,1,1,1,1,1,64,84,68,68,68,68,64,64,104,254,238,238,238,110,104,104,72,222,206,206,78,76,72,72,72,222,206,78,76,76,72,72,72,222,78,76,76,76,72,72,72,94,76,76,76,76,72,72,64,84,68,68,68,68,64,64,64,84,68,68,68,68,64,64,1,20,4,4,4,1,1,1,40,190,174,174,46,42,40,40,8,158,142,14,14,8,8,8,8,158,14,14,12,8,8,8,8,30,14,12,12,8,8,8,1,22,4,4,4,1,1,1,1,20,4,4,4,1,1,1,1,20,4,4,4,1,1,1,1,20,4,4,1,1,1,1,40,190,174,46,42,42,40,40,8,158,14,14,10,8,8,8,8,30,14,14,8,8,8,8,1,22,6,4,1,1,1,1,1,22,4,4,1,1,1,1,1,20,4,4,1,1,1,1,1,20,4,4,1,1,1,1,1,20,4,1,1,1,1,1,40,190,46,42,42,42,40,40,8,30,14,10,10,8,8,8,1,22,6,2,1,1,1,1,1,22,6,1,1,1,1,1,1,22,4,1,1,1,1,1,1,20,4,1,1,1,1,1,1,20,4,1,1,1,1,1,1,20,1,1,1,1,1,1,40,62,42,42,42,42,40,40,1,22,2,2,2,1,1,1,1,22,2,2,1,1,1,1,1,22,2,1,1,1,1,1,1,22,1,1,1,1,1,1,1,20,1,1,1,1,1,1,1,20,1,1,1,1,1,1,1,16,1,1,1,1,1,1,32,50,34,34,34,34,32,32,1,18,2,2,2,1,1,1,1,18,2,2,1,1,1,1,1,18,2,1,1,1,1,1,1,18,1,1,1,1,1,1,1,16,1,1,1,1,1,1,1,16,1,1,1,1,1,1,1,16,1,1,1,1,1,1,32,50,34,34,34,34,32,32,1,18,2,2,2,1,1,1,1,18,2,2,1,1,1,1,1,18,2,1,1,1,1,1,1,18,1,1,1,1,1,1,1,16,1,1,1,1,1,1,1,16,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,2,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,4,4,4,4,1,1,8,142,142,142,142,14,8,8,8,142,142,142,14,12,8,8,8,142,142,14,12,12,8,8,8,142,14,12,12,12,8,8,8,14,12,12,12,12,8,8,1,4,4,4,4,4,1,1,1,4,4,4,4,4,1,1,1,4,4,4,4,1,1,1,8,142,142,142,14,10,8,8,8,142,142,14,14,8,8,8,8,142,14,14,12,8,8,8,8,14,14,12,12,8,8,8,1,6,4,4,4,1,1,1,1,4,4,4,4,1,1,1,1,4,4,4,4,1,1,1,1,4,4,4,1,1,1,1,8,142,142,14,10,10,8,8,8,142,14,14,10,8,8,8,8,14,14,14,8,8,8,8,1,6,6,4,1,1,1,1,1,6,4,4,1,1,1,1,1,4,4,4,1,1,1,1,1,4,4,4,1,1,1,1,1,4,4,1,1,1,1,1,8,142,14,10,10,10,8,8,8,14,14,10,10,8,8,8,1,6,6,2,1,1,1,1,1,6,6,1,1,1,1,1,1,6,4,1,1,1,1,1,1,4,4,1,1,1,1,1,1,4,4,1,1,1,1,1,1,4,1,1,1,1,1,1,8,14,10,10,10,10,8,8,1,6,2,2,2,1,1,1,1,6,2,2,1,1,1,1,1,6,2,1,1,1,1,1,1,6,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,2,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,2,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,2,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,4,4,4,4,1,1,8,142,142,142,142,14,8,8,8,142,142,142,14,12,8,8,8,142,142,14,12,12,8,8,8,142,14,12,12,12,8,8,8,14,12,12,12,12,8,8,1,4,4,4,4,4,1,1,1,4,4,4,4,4,1,1,1,4,4,4,4,1,1,1,8,142,142,142,14,10,8,8,8,142,142,14,14,8,8,8,8,142,14,14,12,8,8,8,8,14,14,12,12,8,8,8,1,6,4,4,4,1,1,1,1,4,4,4,4,1,1,1,1,4,4,4,4,1,1,1,1,4,4,4,1,1,1,1,8,142,142,14,10,10,8,8,8,142,14,14,10,8,8,8,8,14,14,14,8,8,8,8,1,6,6,4,1,1,1,1,1,6,4,4,1,1,1,1,1,4,4,4,1,1,1,1,1,4,4,4,1,1,1,1,1,4,4,1,1,1,1,1,8,142,14,10,10,10,8,8,8,14,14,10,10,8,8,8,1,6,6,2,1,1,1,1,1,6,6,1,1,1,1,1,1,6,4,1,1,1,1,1,1,4,4,1,1,1,1,1,1,4,4,1,1,1,1,1,1,4,1,1,1,1,1,1,8,14,10,10,10,10,8,8,1,6,2,2,2,1,1,1,1,6,2,2,1,1,1,1,1,6,2,1,1,1,1,1,1,6,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,2,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1,1,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,2,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const int perm[8][9] = {
	{0,1,2,3,4,5,6,7,8},
	{6,3,0,7,4,1,8,5,2}, //r
	{8,7,6,5,4,3,2,1,0},
	{2,5,8,1,4,7,0,3,6},
	{2,1,0,5,4,3,8,7,6}, //s
	{0,3,6,1,4,7,2,5,8}, //sr
	{6,7,8,3,4,5,0,1,2},
	{8,5,2,7,4,1,6,3,0},
};
const int compo[8][8] = {
	{0,1,2,3,4,5,6,7},
	{1,2,3,0,7,4,5,6},
	{2,3,0,1,6,7,4,5},
	{3,0,1,2,5,6,7,4},
	{4,5,6,7,0,1,2,3},
	{5,6,7,4,3,0,1,2},
	{6,7,4,5,2,3,0,1},
	{7,4,5,6,1,2,3,0}
};
const u64 U = 0'070'000'000ULL << (3*4);
const u64 L = 0'000'700'000ULL << (3*4);
const u64 C = 0'000'070'000ULL << (3*4);
const u64 R = 0'000'007'000ULL << (3*4);
const u64 D = 0'000'000'070ULL << (3*4);
constexpr u64 capMask[12] = {0, R|D, L|D, L|R, U|D, U|R, U|L, L|R|D, U|R|D, U|L|D, U|L|R, U|L|R|D};
constexpr u32 M30 = 0x3fffffff;
constexpr u32 P10[9] = {100'000'000, 10'000'000, 1'000'000, 100'000, 10'000, 1'000, 100, 10, 1};

using State = u32;
const u32 HASHMAX = (1<<16);
constexpr bool isFinal(State s)
{
	return 0 == ((s-0111111111) & ~s & 0444444444);
}
struct Hashmap {
	u32 *key[2];
	u32 *val[2];
	u32	capG = 1<<12;
	size_t cap[2] = {capG, capG};
	u32 size[2];

	Hashmap() {
		size[0] = 0;
		size[1] = 0;
		key[0] = new u32[HASHMAX]();
		key[1] = new u32[HASHMAX]();
		val[0] = new u32[8*HASHMAX]();
		val[1] = new u32[8*HASHMAX]();
	}

	u32 hash(bool sub, u32 s) {
		u32 h = s;
		h^=(h>>13), h^=(h<<7), h^=(h>>17);
		return h & cap[sub]-1;
	}

	u32* find(bool sub, u32 s) {
		u32 h = hash(sub, s);
		while (key[sub][h] && key[sub][h] != s) {
			h = (h+1) & (cap[sub]-1);
		}
		size[sub] += key[sub][h]==0;
		key[sub][h] = s;
		return &(val[sub][8*h]);
	}

	void clear(bool sub) {
		if (10*size[!sub] > 7*capG && capG < HASHMAX)
			capG *= 2;
		if (cap[sub] != capG) {
			cap[sub] = capG;
		}
		memset(key[sub], 0, cap[sub]*sizeof(u32));
		memset(val[sub], 0, 8*cap[sub]*sizeof(u32));
		size[sub] = 0;
	}
};

Hashmap memo;

constexpr u32 posShift(u8 val, u8 pos) {
	u32 res = val;
	return res << (3*pos);
}

constexpr int at(State s, u8 pos) {
	return (s>>(3*pos))&7;
}

u32 addToRes(State s, u32 cnt[8]) {
	u32 res = 0;
	for (int pos = 0; pos < 9; pos++)
		for (int per = 0; per < 8; per++)
			res += P10[perm[per][pos]] * at(s,pos) * cnt[per];
	return res;
}

constexpr u16 neigh(u32 g, u8 pos) {
	constexpr u16 oobMask[9] = {077, 07, 0707, 070, 0, 0700, 07070, 07000, 07700};
	u64 hood = g;
	hood <<= 3*(8-pos); 
	hood = ((hood&U)>>(3*8)) | ((hood&L)>>(3*7)) | ((hood&R)>>(3*6)) | ((hood&D)>>(3*5));
	return hood | oobMask[pos];
} 

constexpr State nextS(State s, u8 pos, u8 capt) {
	u32 m = capMask[capt]>>(3*(8-pos));

	u32 val = s&m;
	val = val*0111111111;
	val = (val>>(3*8))&7;
	val += capt==0;

	return (s&~m) | posShift(val, pos);
}

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

void insert(bool sub, State s, u32 cnt[8]) {
	pair<u32, u8> p = canon(s);
	
	u32* entry = memo.find(sub, p.first);
	for (int i = 0; i < 8; i++) {
		entry[compo[p.second][i]] += cnt[i];
	}
}

int parse() {
	int depth;
	cin >> depth; cin.ignore();
	u32 s = 0;
	for (int i = 0; i < 9; i++) {
		u32 val;
		cin >> val; cin.ignore();
		s = s | (val<<(3*i));
	}
	u32 cnt[8] = {1,0,0,0,0,0,0,0};
	for (u8 pos = 0; pos < 9; pos++) {
		if (at(s,pos))
			continue;
		u16 capMask = legal[neigh(s, pos)];
		for (int capt = 0; capt < 12; capt++) {
			if (!(capMask & (1<<capt)))
				continue;
			State next = nextS(s, pos, capt);
			insert(0, next, cnt);
		}
	}
	return depth;
}

u32 solve()
{
	int depth = parse();
	u32 res = 0;
	bool sub = 0;
	for (int d = depth-1; d > 0; d--, sub ^= 1) {
		for (int i = 0; i < memo.cap[sub]; i++) {
			if (!memo.key[sub][i])
				continue;
			State s = memo.key[sub][i];
			u32* cnt = &(memo.val[sub][8*i]);
			if (isFinal(s)) {
				res += addToRes(s,cnt);
			}
			for (u8 pos = 0; pos < 9; pos++) {
				if (at(s,pos))
					continue;
				u16 capMask = legal[neigh(s, pos)];
				for (int capt = 0; capt < 12; capt++) {
					if (!(capMask & (1<<capt)))
						continue;
					State next = nextS(s, pos, capt);
					insert(!sub, next, cnt);
				}
			}
		}
		memo.clear(sub);
	}
	for (int i = 0; i < memo.cap[sub]; i++) {
		if (!memo.key[sub][i])
			continue;
		res += addToRes(memo.key[sub][i], &(memo.val[sub][8*i]));
	}

	return res&M30;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << solve() << '\n';
}
