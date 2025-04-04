#include "../inc/Cepha.hpp"

unordered_map<ll, ll> memo;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memo.reserve(1<<20);
	Grid input;
	//Grid next(input, 0, 0);
	//cerr << next;
	//cerr << next.toInt();
	cout << input.solve()%(1<<30) << "\n";
}
