#include "../inc/Cepha.hpp"

unordered_map<ll, ll> memo;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memo.reserve(1<<20);

	int depth;
	cin >> depth; cin.ignore();
	board b = parse();

	cout << solve(depth, b)%(1<<30) << "\n";
}
