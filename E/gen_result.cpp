#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map <string, string> A;
int main()
{
	int n;
	cin >> n;
	while (n --)
	{
		string x, y;
		cin >> x >> y;
		A[x] = y;
	}
	int m;
	cin >> m;
	while (m --)
	{
		string s;
		cin >> s;
		if (A.find(s) != A.end())
			cout << A[s];
		else cout << s;
		if (m) cout << " ";
	}
	cout << endl;
	return 0;
}