#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXN 30000000
#define random() (rand() % MAXN)

void gen(int, int);
void gen_final(int, int);

int main()
{
	srand(time(NULL));
	
	// gen(4, 10);
	// gen(5, 100);
	// gen(6, 1000);
	// gen(7, 10000);
	// gen(8, 50000);
	// gen(9, 100000);
	// gen_final(10, 100000);
	for (int i=11; i<=20; i++) gen(i, abs(rand()%10000));
	return 0;
}

void gen(int n, int m)
{
	char file[16];
	int i;
	FILE *fp;

	sprintf(file, "%d.in", n);
	fp = fopen(file, "w");

	fprintf(fp, "%d\n", m);
	for (i=0; i<m; i++)
	{
		if (i) fprintf(fp, " ");
		fprintf(fp, "%d", random());
	}

	fclose(fp);
}

void gen_final(int n, int m)
{
	char file[16];
	int i;
	FILE *fp;

	sprintf(file, "%d.in", n);
	fp = fopen(file, "w");

	fprintf(fp, "%d\n", m);
	for (i=0; i<m; i++)
	{
		if (i) fprintf(fp, " ");
		fprintf(fp, "%d", MAXN);
	}

	fclose(fp);
}

