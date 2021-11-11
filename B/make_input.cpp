#include <cstdio>
#include <cstdlib>
#include <ctime>

void gen(int n, long long y)
{
	char name[16];
	sprintf(name, "%d.in", n);
	FILE *f = fopen(name, "w");
	
	fprintf(f, "%lld\n", y);
	
	fclose(f);
}

void radom_gen(int n, long long maxn)
{
	char name[16];
	sprintf(name, "%d.in", n);
	FILE *f = fopen(name, "w");
	
	srand((unsigned) time(NULL) + n*998244%114514);
	long long y = 1;
	while (1)
	{
		long long r = y*abs(rand());
		if (r > 0 && 4*r > 0 && 4*r <= maxn) y = 4*r;
		else break;
	}

	fprintf(f, "%lld\n", y);
	fclose(f);
}

int main()
{
	gen(0, 1000);
	for (int i=11; i<=15; i++) radom_gen(i, 1e12);
	for (int i=16; i<=20; i++) radom_gen(i, 1e18);
	return 0;
}