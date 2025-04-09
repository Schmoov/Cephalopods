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
using i32 = uint32_t;
using i16 = uint16_t;
using i8 = uint8_t;

//12 bits : all // not down,right,left,up // ul, ur,ud, lr, ld, rd // new
i16 legal(i16 neigh)
{
    i16 u = neigh >> 9;
    i16 l = neigh >> 6; l &= 7;
    i16 r = neigh >> 3; r &= 7;
    i16 d = neigh & 7;

    i16 res = 0;
    if (u && l && r && d)
        if (u+l+r+d <= 6) res |= 1<<11;
    if (u && l && r)
        if (u+l+r <= 6) res |= 1<<10;
    if (u && l && d)
        if (u+l+d <= 6) res |= 1<<9;
    if (u && r && d)
        if (u+r+d <= 6) res |= 1<<8;
    if (l && r && d)
        if (l+r+d <= 6) res |= 1<<7;
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
int main ()
{
    cout << "const int legal[] ={";
    for (i16 i = 0; i < 07777; i++)
        cout << legal(i) << ",";
    cout << legal(07777) << "};";

}
