#include <cstdio>

void result(int n)
{
	char file_in[16], file_out[16];
	sprintf(file_in, "%d.in", n);
	sprintf(file_out, "%d.out", n);
	FILE *fin = fopen(file_in, "r");
	FILE *fout = fopen(file_out, "w");

	long long a, b;
	fscanf(fin, "%lld%lld", &a, &b);
	long long c = a + b*2;
	fprintf(fout, "%lld\n", c);

	fclose(fin);
	fclose(fout);
}

int main()
{
	for (int i=0; i<=20; i++) result(i);
	return 0;
}