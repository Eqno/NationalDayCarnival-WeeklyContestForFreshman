#include <cstdio>

void result(int n)
{
	char file_in[16];
	sprintf(file_in, "%d.in", n);
	FILE *fin = fopen(file_in, "a");

	fprintf(fin, "\n");

	fclose(fin);
}

int main()
{
	for (int i=1; i<=20; i++) result(i);
	return 0;
}