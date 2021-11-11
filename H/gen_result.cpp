#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 1e6+10;
bool judgeSqrt(long long n)
{
	long long sq = sqrt(n);
	if (sq * sq == n) return true;
	return false;
}
int main()
{
	long long c;
	cin >> c;
	bool f = false;
	for (long long i=1; i<=MAXN && i<c; i++)
		if (c % i == 0)
		{
			c /= i;
			if (i!=1 && c%i==0 || judgeSqrt(c))
			{
				f = true;
				break;
			}
		}
	if (f) puts("yes");
	else puts("no");
	return 0;
}