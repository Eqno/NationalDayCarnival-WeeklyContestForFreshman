#include <cstdio>

void result(int n)
{
	char file_in[16], file_out[16];
	sprintf(file_in, "%d.in", n);
	sprintf(file_out, "%d.out", n);
	FILE *fin = fopen(file_in, "r");
	FILE *fout = fopen(file_out, "w");

	int hs, ms, ss, he, me, se;
	fscanf(fin, "%d:%d:%d%d:%d:%d", &hs, &ms, &ss, &he, &me, &se);
	int now = ((hs*60) + ms)*60 + ss;
	int meet = ((he*60) + me)*60 + se;
	fprintf(fout, "%d\n", meet - now);

	fclose(fin);
	fclose(fout);
}

int main()
{
	for (int i=0; i<=20; i++) result(i);
	return 0;
}