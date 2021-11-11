#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gen(int, int);

int main()
{
	srand(time(NULL));
	gen(0, 1);
	// gen(2, 10);
	// gen(3, 50);
	// gen(4, 100);
	// gen(5, 500);
	// gen(6, 1000);
	// gen(7, 5000);
	// gen(8, 10000);
	// gen(9, 50000);
	// gen(10, 100000);
	// for (int i=11; i<=20; i++) gen(i, abs(rand()%300));
	return 0;
}

void gen(int n, int m)
{
	char file[16];
	int i;
	FILE *fp = NULL;

	sprintf(file, "%d.in", n);
	fp = fopen(file, "w");

	fprintf(fp, "%d\n", m);
	for (i=1; i<=m; i++)
	{
		fprintf(fp, "%0100x ", i);
		fprintf(fp, "%0100x\n", -i);
	}
	fprintf(fp, "%d\n", m);
	for (i=m; i>=1; i--)
	{
		if (i < m)
			fprintf(fp, " ");
		fprintf(fp, "%0100x", -i);
	}

	fclose(fp);
}

