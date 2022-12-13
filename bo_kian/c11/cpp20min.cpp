#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
	vector<int> v = { 0, 1, 2, 3, 4, 5 };
	for (auto i : v) cout << i << ' ';
        cout << '\n';
	for (auto n : { 0, 1, 2, 3, 4, 5 }) cout << n << ' ';
        cout << '\n';
	int a[] = { 0, 1, 2, 3, 4, 5 };
	for (auto n : a) cout << n << ' ';
        cout << '\n';
	for (int n : a) cout << "In loop" << ' ';
        cout << '\n';
	string str = "geeks";
	for (auto c : str) cout << c << ' ';
        cout << '\n';

	map<int, int> MAP( { { 1, 1 }, { 2, 2 }, { 3, 3 } });
	for (auto i : MAP)
		cout << '{' << i.first << ", " << i.second << "}\n";
    for (auto& [key, value]: MAP) {
        cout << key << " has value " << value << endl;
}
}

