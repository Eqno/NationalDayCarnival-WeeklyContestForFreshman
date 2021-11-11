#include <cstdio>

void result(int n)
{
	char file_in[16], file_out[16];
	sprintf(file_in, "%d.in", n);
	sprintf(file_out, "%d.out", n);
	FILE *fin = fopen(file_in, "r");
	FILE *fout = fopen(file_out, "w");

	long long y;
	fscanf(fin, "%lld", &y);
	y -= 4;
	if (y%400 && y%100==0)
		fprintf(fout, "BU!CUN!ZAI!\n");
	else
		fprintf(fout, "QIAO!DAI!MA!\n");

	fclose(fin);
	fclose(fout);
}

int main()
{
	for (int i=0; i<=20; i++) result(i);
	return 0;
}