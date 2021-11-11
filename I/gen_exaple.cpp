#include <iostream>
using namespace std;
#define int long long

int rand_range(int min, int max)
{ return min + (rand() % (max-min+1)); }

void gen(int T, int min1, int max1, int min2, int max2)
{
	char name[16];
	sprintf(name, "%lld.in", T);
	FILE *f = fopen(name, "w");

	int a = rand_range(min1, max1); double b;
	do { b = rand_range(min1, max1); } while (a * b < 2e5);
	double n = rand_range(min2, max2);

	fprintf(f, "%lld %.6f %.6f\n", a, b, n);

	fclose(f);
}

signed main()
{
	for (int i=3; i<=10; i++) gen(i, 1000, 1e5, 0, 1e6);
	for (int i=11; i<=20; i++) gen(i, 1000, 1e5, 1e6, 1e12);
	return 0;
}
