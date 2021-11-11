#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

const int MAXN = 3e+7;

void gen(int);

int main()
{
	int i;
	
	srand(time(NULL));
	
	for (i=11; i<=20; i++) gen(i);
	
	return 0;
}

void gen(int n)
{
	char file_in[16], file_out[16];
	int a, b, c, s;
	double ma, mb, mc;
	FILE *fin, *fout;

	sprintf(file_in, "%d.in", n);
	sprintf(file_out, "%d.out", n);
	fin = fopen(file_in, "w");
	fout = fopen(file_out, "w");

#define random(x) (x = rand() % MAXN)
#define calc(x) (m##x = x * 1. / s * MAXN)
	random(a); random(b); random(c);
	s = a + b + c;
	calc(a); calc(b); calc(c);
#undef random(x)
#undef calc(x)

	fprintf(fin, "%d %d %d", a, b, c);
	fprintf(fout, "%.2lf\n%.2lf\n%.2lf\n", ma, mb, mc);
	
	fclose(fin);
	fclose(fout);
}

