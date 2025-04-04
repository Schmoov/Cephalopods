#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int depth;
    cin >> depth; cin.ignore();
	cerr << depth << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int value;
            cin >> value; cin.ignore();
			cerr << value << (i==2&&j==2 ? "":" ");
        }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "0" << endl;
}
