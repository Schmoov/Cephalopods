#include <bits/stdc++.h>
using namespace std;


int main() {
    int res[10][55];
    memset(res,0,sizeof(res));

    for (int i1 = 0; i1 < 7; i1++) {
    for (int i2 = 0; i2 < 7; i2++) {
    for (int i3 = 0; i3 < 7; i3++) {
    for (int i4 = 0; i4 < 7; i4++) {
    for (int i5 = 0; i5 < 7; i5++) {
    for (int i6 = 0; i6 < 7; i6++) {
    for (int i7 = 0; i7 < 7; i7++) {
    for (int i8 = 0; i8 < 7; i8++) {
    for (int i9 = 0; i9 < 7; i9++) {
         res[!!i1+!!i2+!!i3+!!i4+!!i5+!!i6+!!i7+!!i8+!!i9][i1+i2+i3+i4+i5+i6+i7+i8+i9]++;
    }}}}}}}}}
    int i ;
    for (int i1 = 0; i1 < 10; i1++) {
        int cnt = 0;
        int mx = 0;
    for (int i2 = 0; i2 < 55; i2++) {
        if (!res[i1][i2])
            continue;
        cnt++;
        mx = max(mx, res[i1][i2]);
        if (res[i1][i2]== mx)
            i = i2;

    //std::cout << res[i1][i2] << " ways to combine " << i1 << " die summing to "<<i2 << '\n';
    }
    std::cout << "~~~~~" << i1 << " die makes " << mx << " arrangements at most reached for sum="<< i<<"~~~~~\n\n";
    }
}

