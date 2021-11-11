#include <cstdio>
#include <cstdlib>
#include <ctime>

void gen(int n, long long a, long long b)
{
	char name[16];
	sprintf(name, "%d.in", n);
	FILE *f = fopen(name, "w");
	
	fprintf(f, "%lld %lld\n", a, b);
	
	fclose(f);
}

void radom_gen(int n, long long maxn)
{
	char name[16];
	sprintf(name, "%d.in", n);
	FILE *f = fopen(name, "w");
	
	srand((unsigned) time(NULL) + n*998244%114514);
	// long long a = 1, b = 1;
	// while (1)
	// {
	// 	long long r = a*abs(rand());
	// 	if (r > 0 && r <= maxn) a = r;
	// 	else break;
	// }
	// while (1)
	// {
	// 	long long r = b*abs(rand());
	// 	if (r > 0 && r <= maxn) b = r;
	// 	else break;
	// }
	long long a = abs(rand()%maxn);
	long long b = abs(rand()%maxn);
	fprintf(f, "%lld %lld\n", a, b);
	fclose(f);
}

int main()
{
	gen(0, 1, 0);
	gen(1, 0, 1);
	gen(2, 1, 1);
	gen(3, 0, 0);
	gen(4, 1e18, 1e18);
	gen(5, (long long)1e18-1, (long long)1e18-1);
	for (int i=6; i<=10; i++) radom_gen(i, 1e6);
	// for (int i=11; i<=15; i++) radom_gen(i, 1e12);
	// for (int i=16; i<=20; i++) radom_gen(i, 1e18);
	return 0;
}