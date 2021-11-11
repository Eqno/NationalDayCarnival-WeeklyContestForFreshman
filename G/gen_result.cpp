#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+10;
int f[MAXN], dep[MAXN];
int getd(int x)
{
	if (dep[x]) return dep[x];
	if (f[x] == 0) return 1;
	return dep[x] = getd(f[x]) + 1;
}
int read(string s)
{
	int res = 0;
	for (int i=5; i<s.size(); i++)
		res = res * 10 + s[i] - '0';
	return res;
}
int main()
{
	int n, d;
	cin >> n >> d;
	for (int i=1; i<n; i++)
	{
		string x, y;
		cin >> x >> y;
		int a = read(x), b = read(y);
		f[b] = a;
	}
	for (int i=1; i<=n; i++)
		dep[i] = getd(i);
	int depth = 0;
	for (int i=1; i<=n; i++)
		depth = max(depth, dep[i]);
	cout << depth << endl;
	if (depth >= d) cout << "deep xue xi is nb" << endl;
	else cout << "shen du learning is fw" << endl;
	return 0;
}
