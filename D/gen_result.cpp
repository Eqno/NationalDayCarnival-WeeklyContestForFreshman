#include <cstdio>

void result(int n)
{
	char file_in[16], file_out[16];
	sprintf(file_in, "%d.in", n);
	sprintf(file_out, "%d.out", n);
	FILE *fin = fopen(file_in, "r");
	FILE *fout = fopen(file_out, "w");

	int x, y, z;
	fscanf(fin, "%d%d%d", &x, &y, &z);
	double money = 3e7;
	if (x==0 && y==0 && z==0)
		fprintf(fout, "%.2f\n%.2f\n%.2f\n", money/3, money/3, money/3);
	else
	{
		double c = (double) x / (x+y+z) * money;
		double p = (double) y / (x+y+z) * money;
		double j = (double) z / (x+y+z) * money;
		fprintf(fout, "%.2f\n%.2f\n%.2f\n", c, p, j);
	}

	fclose(fin);
	fclose(fout);
}

int main()
{
	for (int i=0; i<=20; i++) result(i);
	return 0;
}