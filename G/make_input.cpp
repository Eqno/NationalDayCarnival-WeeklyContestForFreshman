#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 1e5+10;
const int MAXD = 100;
int f[MAXN], dep[MAXN];
int getd(int x)
{
	if (dep[x]) return dep[x];
	if (f[x] == 0) return 1;
	return dep[x] = getd(f[x]) + 1;
}
void gen(int T, int maxn)
{
	char name[16];
	sprintf(name, "%d.in", T);
	FILE *file = fopen(name, "w");

	memset(f, 0, sizeof f);
	memset(dep, 0, sizeof dep);
	int n = abs(rand()%maxn);
	int m = n + 1;
	int d = abs(rand()%m);
	fprintf(file, "%d %d\n", n, d);
	for (int i=2; i<=m; i++)
	{
		int flag = 1;
		while (flag)
		{
			int fa = (rand()%(i-1))+1;
			f[i] = fa;
			int newd = getd(i);
			if (newd <= MAXD)
			{
				dep[i] = newd;
				fprintf(file, "xuexi%d xuexi%d\n", fa, i);
				flag = 0;
			}
			else f[i] = 0;
		}
	}
	fclose(file);
}
void gen_line(int T, int maxn)
{
	char name[16];
	sprintf(name, "%d.in", T);
	FILE *file = fopen(name, "w");

	int n = maxn;
	int m = n + 1;
	int d = abs(rand()%m);
	fprintf(file, "%d %d\n", n, d);
	for (int i=2; i<=m; i++)
		fprintf(file, "xuexi%d xuexi%d\n", i-1, i);

	fclose(file);
}
void gen_flower(int T, int maxn)
{
	char name[16];
	sprintf(name, "%d.in", T);
	FILE *file = fopen(name, "w");

	int n = maxn;
	int m = n + 1;
	int d = abs(rand()%m);
	fprintf(file, "%d %d\n", n, d);
	for (int i=2; i<=m; i++)
		fprintf(file, "xuexi1 xuexi%d\n", i);

	fclose(file);
}

int main()
{
	gen(0, 1);
	gen(3, 10);
	gen(4, 100);
	gen(5, 1000);
	gen(6, 10000);
	gen(7, 50000);
	gen(8, 100000);
	gen_line(9, 10);
	gen_line(10, 89);
	gen_line(11, 130);
	gen_flower(12, 10);
	gen_flower(13, 1145);
	gen_flower(14, 100000);
	gen(15, 100000);
	gen(16, 100000);
	gen(17, 100000);
	gen(18, 100000);
	gen(19, 100000);
	gen(20, 100000);
	return 0;
}